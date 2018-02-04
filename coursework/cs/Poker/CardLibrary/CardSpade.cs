using System;

namespace CardLibrary
{
	public class CardSpade : SuperCard
	{
		private Suit _cardSuit = Suit.Spade;

		public override Suit cardSuit
		{
			get
			{
				return _cardSuit;
			}
		}

		public CardSpade(Rank pip)
		{
			cardsRank = pip;
		}

		// Display a Spade card
		public override void Display()
		{
			// Change color
			Console.BackgroundColor = ConsoleColor.White;
			Console.ForegroundColor = ConsoleColor.Black;

			// Display the card
			Console.WriteLine("{0} of {1}s ♠", cardsRank, cardSuit);

			// Clear the original color
			Console.ResetColor();
		}
	}
}
