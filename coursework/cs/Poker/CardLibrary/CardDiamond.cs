using System;

namespace CardLibrary
{
	public class CardDiamond : SuperCard
	{
		private Suit _cardSuit = Suit.Diamond;

		public override Suit cardSuit
		{
			get
			{
				return _cardSuit;
			}
		}

		public CardDiamond(Rank pip)
		{
			cardsRank = pip;
		}

		// Display a Diamond card
		public override void Display()
		{
			// Change color
			Console.BackgroundColor = ConsoleColor.White;
			Console.ForegroundColor = ConsoleColor.DarkRed;

			// Display the card
			Console.WriteLine("{0} of {1}s ♦", cardsRank, cardSuit);

			// Clear the original color
			Console.ResetColor();
		}
	}
}
