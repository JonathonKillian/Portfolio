using System;

namespace CardLibrary
{
	public class CardHeart : SuperCard
	{
		private Suit _cardSuit = Suit.Heart;

		public override Suit cardSuit
		{
			get
			{
				return _cardSuit;
			}
		}

		public CardHeart(Rank pip)
		{
			cardsRank = pip;
		}
		// Display a Heart card
		public override void Display()
		{
			// Change color
			Console.BackgroundColor = ConsoleColor.White;
			Console.ForegroundColor = ConsoleColor.Red;

			// Display the card
			Console.WriteLine("{0} of {1}s ♥", cardsRank, cardSuit);

			// Clear the original color
			Console.ResetColor();
		}
	}
}
