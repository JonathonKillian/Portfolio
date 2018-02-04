using System;

namespace CardLibrary
{
	public class CardClub : SuperCard
	{
		private Suit _cardSuit = Suit.Club;

		public override Suit cardSuit
		{
			get
			{
				return _cardSuit;
			}
		}

		public CardClub(Rank pip)
		{
			cardsRank = pip;
		}

		// Display a club card
		public override void Display()
		{
			// Change color
			Console.BackgroundColor = ConsoleColor.White;
			Console.ForegroundColor = ConsoleColor.Blue;

			// Display the card
			Console.WriteLine("{0} of {1}s ♣", cardsRank, cardSuit);

			// Clear the original color
			Console.ResetColor();
		}
	}

}
