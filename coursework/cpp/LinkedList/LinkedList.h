#pragma once

// External Definition files
// -------------------------
#include <string>
#include <sstream>

using namespace std;

/*******************************************************************************
*      Class: LinkedList<T>
* Base Class: None
*
* Programmer: Jon Killian
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		06/01/2017	Initial Release
*
* Class Description
* -----------------
* This class template provides methods and struct for constructing and
* performing actions on a linked list; including: adding a node, cloning a
* linked list, stringify a linked list suitable for displaying, properly free
* allocated memory, removing a node, and reversing a linked list
*
* --------------------------- Public Methods Interface -------------------------
*		Method								Description
* ----------------------	----------------------------------------------------
* LinkedList()				Default constructor
* LinkedList(LinkedList)	Copy Constructor
* isMember(T)				Checks if a value exists among the nodes
* toString()				Stringifies the node values for displaying purposes
* add(T)					Adds a new value (node) to front of list
* remove(T)					Removes a value (node) from list
* reverse()					Reverses a linked list in place
*
* --------------------------------- Private Methods ----------------------------
*		Method								Description
* ----------------------	----------------------------------------------------
* ListNode::ListNode()		Initializing constructor for ListNode struct
*
* --------------------- Private Data Members (Static Const) --------------------
*  Type			  Name						Description
* ------	----------------	------------------------------------------------
* None
*
* ---------------------- Private Data Members (Non-static) ---------------------
*  Type			  Name						Description
* ------	----------------	------------------------------------------------
* struct	ListNode			Defines the nodes used in the linked list
*******************************************************************************/
template <class T>
class LinkedList
{
public:

	// Constructors and Destructor

	LinkedList() : head(nullptr)					// Default constructor
	{}
	LinkedList(const LinkedList<T> &);				// Copy constructor
	~LinkedList();									// Destructor

	// Observers

	bool isMember(const T &) const;					// Is value present in list
	string toString() const;						// Stringify node values

	// Mutators

	void add(T);									// Add node to front of list
	void remove(T);									// Remove value from list
	void reverse();									// Reverse list in place

private:

	// Internal struct to provide the node objects for the linked list
	struct ListNode {
		T value;
		ListNode * next;

		ListNode(T nodeValue, ListNode * nextListNode = nullptr)
			: value(nodeValue), next(nextListNode)
		{}
	};

	ListNode * head;								// Head of linkedList
};

/*******************************************************************************
*
* Constuctors & Destructor
*
*******************************************************************************/

/***************
* Method:		Copy Constructor
* Description:	Initializes with values from the passed-in class object
*
*				In the order of the text book challenges the assignment is based
*				on, reverse follows adding the copy constructor; so instead of
*				just adding all and calling reverse() afterwards, I took up the
*				challenge to rearrange on the go.
*
* Input(s):		const & LinkedList<T> copyList
*
* Output(s):	None
****************/
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & copyList) : head(nullptr)
{
	add(copyList.head->value);						// Add new head
	// If the other linked list has 0-1 nodes, we're done.
	if (head == nullptr || copyList.head->next == nullptr) {
		return;
	}

	// There are more nodes. Iterate through them, adding them (adds to front),
	// and move them to the end of the linked list
	ListNode * copyNode = copyList.head->next;
	ListNode * lastNode = head;

	do {
		add(copyNode->value);						// Copy node value
		lastNode->next = head;						// attach its node to end
		head = head->next;							// Move head to "true" head
		lastNode = lastNode->next;					// Move to new last node
		copyNode = copyNode->next;					// Move to next node to copy
	} while (copyNode != nullptr);
	lastNode->next = nullptr;						// Break the circle
}

/***************
* Method:		Destructor
* Description:	Frees any dynamically acquired resources
*
* Input(s):		None
*
* Output(s):	None
****************/
template <class T>
LinkedList<T>::~LinkedList() {
	while (head != nullptr) {
		ListNode * node = head->next;

		delete head;
		head = node;
	}
}

/*******************************************************************************
*
* Methods: Public Observers
*
*******************************************************************************/

/***************
* Method:		isMember(T) const
* Description:	Returns true/false if the parameter of templated type is found
*				among the nodes of the linked list.
*
*				Note: empty list just returns false
*
* Input(s):		T value	(value, of templated type, to find in the linked list)
*
* Output(s):	(bool) was the value found?
****************/
template <class T>
bool LinkedList<T>::isMember(const T & value) const {
	for (ListNode * node = head; node != nullptr; node = node->next) {
		if (node->value == value) {
			return true;
		}
	}

	// If the loop exits, the value is not present in the linked list
	return false;
}

/***************
* Method:		toString() const
* Description:	Returns a string containing all the node values in a
*				comma-delimited list within a pair of square brackets, ready for
*				displaying to console.
*
* Input(s):		None
*
* Output(s):	(string) string contents of a stringstream (stream)
****************/
template <class T>
string LinkedList<T>::toString() const {
	const int PLACES = 2;					// 2 places past the decimal point
	ostringstream stream;

	stream << fixed << setprecision(PLACES) << '[';
	if (head != nullptr) {
		ListNode * node = head;

		stream << head->value;
		for (node = node->next; node != nullptr; node = node->next) {
			stream << ", " << node->value;
		}
	}
	stream << ']';

	return stream.str();
}

/*******************************************************************************
*
* Methods: Public Mutators
*
*******************************************************************************/

/***************
* Method:		add(T)
* Description:	Adds the passed-in value, wrapped in a node, to the front of the
*				linked list
*
* Input(s):		T value	(value, of templated type, to add to the linked list)
*
* Output(s):	(void)
****************/
template <class T>
void LinkedList<T>::add(T value) {
	// Add a new node in front of the (if) existing head node.
	head = new ListNode(value, head);
}

/***************
* Method:		remove(T)
* Description:	Remove a node containing the passed-in value
*
* Input(s):		T value	(value, of templated type, to be removed)
*
* Output(s):	(void)
****************/
template <class T>
void LinkedList<T>::remove(T value) {
	ListNode * current = head;

	// Check head first
	if (current != nullptr && value == current->value) {
		head = current->next;
		delete current;
		return;
	}
	// Check the rest of the nodes from "parent" node
	while (current->next != nullptr) {
		if (value == current->next->value) {
			ListNode * removeNode = current->next;	// Remember node to remove

			current->next = current->next->next;	// Drop it from linked list
			delete removeNode;						// Now it can be freed
			return;									// It's deleted; exit
		}
		current = current->next;					// move to next node
	}

	// If loop has terminated, the value to removed was not found; could throw
	// exception here.
}

/***************
* Method:		reverse()
* Description:	Reverses the list of nodes in the linked list in place
*
* Input(s):		None
*
* Output(s):	(void)
****************/
template <class T>
void LinkedList<T>::reverse() {
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	ListNode * reversed = nullptr;
	// To not make a circular linked list, set a pointer to the tail and
	// disconnect it from the head (which will be reassigned below)
	ListNode * current = head->next;
	head->next = nullptr;

	// Loosely, we are popping the head's next node and adding it in front of
	// head until the last node has been "popped" and moved
	do {
		reversed = current;
		current = current->next;
		reversed->next = head;
		head = reversed;
	} while (current != nullptr);
}
