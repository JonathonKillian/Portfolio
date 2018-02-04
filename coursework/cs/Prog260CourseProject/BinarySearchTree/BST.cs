using System;
using System.Collections.Generic;

namespace BinarySearchTree {
	// Maybe should have renamed to KeyedBST. Key is just an integer, ValueType
	// represents the data type of the data held in the nodes.
	public class BST<ValueType> {
		private const string ERROR_NO_KEY = "Unknown key";
		private const string ERROR_DUPLICATE_KEY = "Duplicate key";
		private const string ERROR_EMPTY_TREE = "Empty Binary Search Tree";

		// The root of the tree, top of the tree, or first node in the tree
		Node rootNode;

		public List<int> Keys {
			get {
				List<int> keys = new List<int>();

				// Collect the keys from each node
				TraverseTree(rootNode, node => keys.Add(node.Key));

				return keys;
			}
		}

		// Count is only modifiable in class methods
		public int Count {get; private set;}

		public bool Empty {
			get {
				return rootNode == null;
			}
		}

		// Quick method to see if any data exists in the Tree.
		public bool HasEntries {
			get {
				return rootNode != null;
			}
		}

		// our inner "node" class.
		private class Node {
			public int Key {get; set;}
			public ValueType Value	{get; set;}
			public Node Left {get; set;}
			public Node Right {get; set;}

			public Node(int key, ValueType value) {
				Key   = key;
				Value = value;
			}
		}

		public void Add(int key, ValueType value) {
			// Deal with an empty BST by adding a root node
			// LeftNode and RightNode will default to null, which is correct
			if (Empty) {
				rootNode = new Node(key, value);
			} else {
				// Need to walk the 2 dim tree to find where to add this

				// Since we got here, we know root is not empty and we can
				// create the node to be added
				Node current = rootNode;
				Node newNode = new Node(key, value);

				// Search for the correct empty child node
				while (true) {
					if (key < current.Key) {
						if (current.Left == null) {
							current.Left = newNode;
							break;					// Node added, leaving loop
						}
						// Else, move down the left path and re-loop
						current = current.Left;
					} else if (key > current.Key) {
						if (current.Right == null) {
							current.Right = newNode;
							break;					// Node added, leaving loop
						}
						// Else, move down the right path and re-loop
						current = current.Right;
					} else {
						// Key is already present in the BST; duplicate keys are
						// not allowed
						throw new ArgumentException(ERROR_DUPLICATE_KEY);
					}
				}
			}

			// Tracking number of nodes
			++Count;
		}

		public ValueType Remove(int key) {
			// Pre-req: A binary Search Tree with nodes
			if (Empty) {
				throw new ArgumentException(ERROR_EMPTY_TREE);
			}

			// In case we need to alter the root node. The key & value do not
			// matter as this node is never checked. Only needed to connect the
			// root to it
			Node rootParentNode = new Node(0, default(ValueType));
			rootParentNode.Left = rootNode;

			// Start searching at the root/top node
			Node parentNode  = rootParentNode;
			Node currentNode = rootNode;
			// Track which of the parent's child node we're attaching grandchild
			// node to
			bool wentLeft = true;

			// Find the node
			while (currentNode!= null && currentNode .Key != key) {
				parentNode = currentNode;
				if (key < currentNode.Key) {
					currentNode = currentNode.Left;
					wentLeft = true;
				} else {
					currentNode = currentNode.Right;
					wentLeft = false;
				}
			}

			// We need to be at the node to be removed
			if (currentNode == null) {
				throw new ArgumentException(ERROR_NO_KEY);
			}

			// Track the number of nodes
			--Count;

			// Return the removed node's value for documentation
			ValueType removedValue = currentNode.Value;

			// Are there 2 children?
			if (currentNode.Left != null && currentNode.Right != null) {
				// Save a reference to the node to be removed by overwriting
				Node replaceNode = currentNode;

				// Start on the node's left child node.
				parentNode = currentNode;
				currentNode = currentNode.Left;
				wentLeft = true;
				// Move down to the furthest right node
				while (currentNode.Right != null) {
					wentLeft = false;
					parentNode = currentNode;
					currentNode = parentNode.Right;
				}

				// Move this node's key and value to the "node to be removed"
				replaceNode.Key = currentNode.Key;
				replaceNode.Value = currentNode.Value;

				//***********************************************************
				// Now we have a new node to remove, one with at most 1 child
				// node. Continue to the 0/1 child path
				//***********************************************************
			}

			// The node has at most 1 child.
			if (currentNode.Left == null) {
				// Either RightNode is the child or there is no child, which
				// means RightNode is set to null (which is ok)
				currentNode = currentNode.Right;
			} else {
				// LeftNode is the present child
				currentNode = currentNode.Left;
			}

			// Remove the node
			if (wentLeft) {
				parentNode.Left = currentNode;
			} else {
				parentNode.Right = currentNode;
			}

			// Deattach root/top from temporary node
			rootNode = rootParentNode.Left;

			return removedValue;
		}  // end of Remove method

		public ValueType Find(int targetKey) {
			// Pre-req: A binary Search Tree with nodes
			if (Empty) {
				throw new ArgumentException(ERROR_EMPTY_TREE);
			}

			Node current = rootNode;

			// Iterate through the tree for the target key
			do {
				if (targetKey == current.Key) {		// A match? We're done
					return current.Value;
				}
				// Not found, going deeper
				current = targetKey < current.Key ? current.Left : current.Right;
			} while (current != null);

			// Empty tree or key not found
			throw new ArgumentException(ERROR_NO_KEY);
		}

		// Act on, "collect()," each node. Nominally, collect a reference to
		// each node's key or value; This Traverse is an in-order traversal,
		// resulting in acting on each node in ascending numerical order.
		private void TraverseTree(Node current, Action<Node> collect) {
			if (current == null) {
				return;					// Nothing can be done on empty node
			}

			TraverseTree(current.Left, collect);
			collect(current);
			TraverseTree(current.Right, collect);
		}
	}
}
