using System;
using CardLibrary;

namespace Poker
{
	class Program
	{
		static void Main(string[] args)
		{
			const int HAND_SIZE = 5;
			const int DISCARD_CARDS = 1;
			const int PLAYERS = 2;
			const int START_BALANCE = 10;
			const int BET = 1;

			int howManyCards = HAND_SIZE;
			int totalCardsDrawn = (HAND_SIZE+DISCARD_CARDS) * PLAYERS;
			int balance = START_BALANCE;

			// Just 'cause I'm curious
			//int handsPlayed = 0;
			//int handsWon = 0;

			bool won = false;

			// Instantiate a deck of cards.
			CardSet myDeck = new CardSet();

			// Declare the 2 hands. Instantiated in myDeck.GetCards()
			SuperCard[] computerHand;
			SuperCard[] playersHand;

			// Set screen colors
			SetScreenColors();
			Console.Clear();	// To actually change the background color

			// Introduction
			Console.Write(
				"Welcome to Quark's game of Poker!\n\n" +
				"You play against the dealer who follows the same rules as " +
				"you do.\n\n" +
				"You will start with ${0}. " +
				"The bet is ${1} for each hand played.\n\n" +
				"When you are out of money, you are out of the game.\n\n" +
				"You will be given {2} cards each hand.\n\n" +
				"You may replace {3} card.\n\n" +
				"Flushes, all cards in the same suit, automatically win,\n" +
				"else whoever has the higher scoring hand wins.\n\n" +
				"Dealer wins on ties. Them's the rules.\n\n" +
				"Press Enter to play your first hand.",
				balance, BET, howManyCards, DISCARD_CARDS);
			Console.ReadLine();	// Pause for reading.

			// Loop until player's out of money
			while (balance > 0)
			{
				// Clear the screen
				Console.Clear();

				// Shuffle the cards
				myDeck.ShuffleCards(totalCardsDrawn);

				// Generate new hands for each player
				computerHand = myDeck.GetCards(howManyCards);
				playersHand = myDeck.GetCards(howManyCards);

				// Sort the hands by suit and rank
				Array.Sort(computerHand);
				Array.Sort(playersHand);

				// Display the hands
				DisplayHands(computerHand, playersHand);

				// Allow players to change a card
				ComputerDrawsOne(computerHand, myDeck);
				PlayerDrawsOne(playersHand, myDeck);

				// Re-sort the hands & re-display to show any new cards
				Array.Sort(computerHand);
				Array.Sort(playersHand);
				Console.Clear();
				DisplayHands(computerHand, playersHand);

				// Compare the hands
				won = CompareHands(computerHand, playersHand);

				// Display the winner and adjust the player's balance
				if (won)
				{
					balance += BET; // Player won the pot
					Console.WriteLine("You win!");
					//++handsWon;		// Track wins for grins
				}
				else
				{
					balance -= BET; // Computer won the pot
					Console.WriteLine("Dealer wins.");
				}

				// Just 'cause I'm curious
				//Console.WriteLine(
				//	"\nYou've won {0} out of {1} hands played",
				//	handsWon, ++handsPlayed);

				// If the player can still play, display balance and
				// wait for User to press Enter
				if (balance > 0)
				{
					Console.Write(
						"\nYour balance is now ${0,-3} " +
						"Press Enter for another hand"
						, balance);
					Console.ReadLine();	// Let User decide to continue
				}
			}

			Console.WriteLine(
				"Sorry, you are out of funds. Please come again soon!");
			Console.ReadLine();	// Pause for reading.
		}

		// Moved the color assignment to its own function as there are
		// multiple places I need to set/restore the colors.
		private static void SetScreenColors()
		{
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.BackgroundColor = ConsoleColor.DarkBlue;
		}

		private static void DisplayHands(SuperCard[] computerHand,
										 SuperCard[] playersHand)
		{
			Console.WriteLine("Dealer's hand:\n");
			foreach (SuperCard card in computerHand)
			{
				card.Display();
			}
			SetScreenColors();  // Reset the colors.

			Console.WriteLine("\n\nYour hand:\n");
			foreach (SuperCard card in playersHand)
			{
				card.Display();
			}
			SetScreenColors();  // Reset the colors.
			Console.WriteLine();
		}

		private static bool CompareHands(SuperCard[] computerHand,
								 SuperCard[] playersHand)
		{
			int computerScore = 0;
			int playerScore = 0;

			// Flushes beat hand's score and Computer wins ties.
			if (Flush(computerHand))
			{
				++computerScore;	// For the return compare
				//Console.Write("Dealer has a flush. ");
			}
			else if (Flush(playersHand))
			{
				++playerScore;		// For the return compare
				//Console.Write("You have a flush! ");
			}
			else
			{
				//Console.WriteLine("Neither has a flush");
				// No flushes, so compare card points
				// Hands should be the same length, so use the same loop
				for (int card = 0; card < computerHand.Length; ++card)
				{
					computerScore += (int)computerHand[card].cardsRank;
					playerScore   += (int)playersHand[card].cardsRank;
				}
			}

			// Return whether the Player scored more than the computer
			return playerScore > computerScore;
		}

		private static bool Flush(SuperCard[] hand)
		{
			SuperCard first = hand[0];
			int count = 1;	// Count the first card

			for (int card = 1; card < hand.Length; ++card)
			{
				if (first.Equals(hand[card]))
				{
					++count;
				}
			}

			// If count matches hand's length, we've a flush
			return count == hand.Length;
		}

		private static void ComputerDrawsOne(SuperCard[] hand, CardSet deck)
		{
			const Rank THESHOLD = Rank.Seven;

			int lowest = 0;

			if (!Flush(hand))
			{
				// Find the lowest scoring card
				for (int card = 1; card < hand.Length; ++card)
				{
					if (hand[card].cardsRank < hand[lowest].cardsRank)
					{
						lowest = card;
					}
				}

				// Does it meet a threshold of 7 points?
				if (hand[lowest].cardsRank < THESHOLD)
				{
					hand[lowest] = deck.GetOneCard();
				}
			}
		}

		private static void PlayerDrawsOne(SuperCard[] hand, CardSet deck)
		{
			const int INVALID_CARD = -1;
			const int STAND_PAT = 0;
			const int MIN_CARD = 1;

			int maxCard = hand.Length;
			int card = INVALID_CARD;

			do
			{
				Console.Write(
					"Enter {0} to stand pat or {1}-{2} to replace a card: ",
					STAND_PAT, MIN_CARD, maxCard);
				// Accept input and convert to integer
				if (!int.TryParse(Console.ReadLine(), out card))
				{
					// User type in a non-integer, which is caught in next if
					card = INVALID_CARD;
				}
				if (card < STAND_PAT || card > maxCard)
				{
					Console.WriteLine("Invalid selection, please try again");
					card = INVALID_CARD;		// Set to re-prompt
				}
				//else if (card == STAND_PAT)
				//{
				//	if (!confirmChoice("You are standing pat"))
				//	{
				//		card = INVALID_CARD;
				//	}
				//}
				else if (card != STAND_PAT)
				{
					--card;			// Change to zero-based for array
					hand[card].Display();
					SetScreenColors();
					if (confirmChoice("Replace"))
					{
						hand[card] = deck.GetOneCard();
					}
					else
					{
						card = INVALID_CARD;	// Set to re-prompt
					}
				}
			} while (card == INVALID_CARD);
		}

		private static bool confirmChoice(string prompt)
		{
			const string YES = "Y";
			const string NO = "N";

			string choice = YES;

			do
			{
				Console.Write("{0} ({1}/{2})? ", prompt, YES, NO);
				choice = Console.ReadLine().ToUpper();
				if (choice != YES && choice != NO)
				{
					Console.WriteLine("Please answer {0} or {1} only",
						YES, NO);
				}
			} while (choice != YES && choice != NO);

			return choice == YES;
		}
	}
}
