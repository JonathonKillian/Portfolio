using System;

namespace CardLibrary
{
	public class CardSet
	{
		private SuperCard[] cardArray;
		private Random rng = new Random();	// Random Number Generator
		private int cardsDrawn = 0;

		public SuperCard this[int card]
		{
			get
			{
				return cardArray[card];
			}
			// No set, the Caller not allowed to set the card
		}

		public int Length
		{
			get
			{
				return cardArray.Length;
			}
			// No set; read-only property
		}

		// Create a deck of cards based on whats in the Suit and Rank
		// enum classes.
		public CardSet()
		{
			int cardIndex = 0;		// Used to iterate through the array

			// Get number of ranks, suits & total cards
			int numberRanks = Enum.GetNames(typeof(Rank)).Length;
			int numberSuits = Enum.GetNames(typeof(Suit)).Length;
			int numberCards = numberRanks * numberSuits;

			// Create the array here so as to use the calculated size.
			cardArray = new SuperCard[numberCards];

			// Enum.GetValues returns objects, so why not let Foreach do the
			// casting for us?
			foreach (Suit suit in Enum.GetValues(typeof(Suit)))
			{
				foreach(Rank rank in Enum.GetValues(typeof(Rank)))
				{
					cardArray[cardIndex++] = MakeCard(suit, rank);
				}
			}
		}

		// Return a new child card class based on the enum passed in.
		public SuperCard MakeCard(Suit suit, Rank rank)
		{
			// Parent class needs to hold the child class
			SuperCard card = null;

			// "Cast" Suit enum to proper SuperCard child class
			switch (suit)
			{
			case Suit.Club:
				card = new CardClub(rank);
				break;
			case Suit.Diamond:
				card = new CardDiamond(rank);
				break;
			case Suit.Heart:
				card = new CardHeart(rank);
				break;
			case Suit.Spade:
				card = new CardSpade(rank);
				break;
			}

			// Return the new card
			return card;
		}

		public SuperCard[] GetCards(int howManyCards)
		{
			// Instantiate a temporary hand, array, of cards
			SuperCard[] hand = new SuperCard[howManyCards];

			// Add cards to the hand.
			// For this phase, is okay to get same card.
			for (int card = 0; card < howManyCards; ++card)
			{
				hand[card] = GetOneCard();
				//hand[card] = cardArray[cardsDrawn++];
			}

			// Return the hand
			return hand;
		}

		// Get one card from the deck that's not already in play
		// Deck's already shuffled by this time, so 
		public SuperCard GetOneCard()
		{
			return cardArray[++cardsDrawn];
		}

		// Based on Fisher-Yates algorithm
		// Source: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
		public void ShuffleCards(int howManyCards = 0)
		{
			int numberCards = Length;
			int lastCard = numberCards - 1;
			int shuffleCard = 0;
			SuperCard hold = null;

			if (howManyCards > 0 && howManyCards <= lastCard)
				lastCard = howManyCards;

			for (int card = 0; card < lastCard; ++card)
			{
				// Randomnly choose a card between card and length of cardArray
				shuffleCard = rng.Next(card, numberCards);

				// Swap the found card with the "current" card
				hold = cardArray[shuffleCard];
				cardArray[shuffleCard] = cardArray[card];
				cardArray[card] = hold;
			}

			// Reset the number of cards drawn
			cardsDrawn = 0;
		}
	}
}
