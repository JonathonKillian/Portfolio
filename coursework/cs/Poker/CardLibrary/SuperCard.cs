using System;

namespace CardLibrary
{
	public abstract class SuperCard : IComparable<SuperCard>, IEquatable<SuperCard>
    {
		public Rank cardsRank {get; set;}
		public abstract Suit cardSuit {get;}

		public abstract void Display();

		// Compares 2 cards by suit and, if need be, by rank utilizing the
		// fact the enums are specialized ints and thus can be subtracted.
		public int CompareTo(SuperCard other)
		{
			//const int LESS_THAN      = -1;
			const int EQUAL_TO       =  0;
			const int GREATER_THAN   =  1;

			// leg is short for Less than, Equal or Greater than.
			int leg = EQUAL_TO;

			// Nulls are considered less than any other valid value
			if (other == null)
			{
				leg = GREATER_THAN;
			}
			else
			{
				// Subtracting will give + for >, - for < or 0 for ==
				leg =  (int) cardSuit - (int) other.cardSuit;

				if (leg == EQUAL_TO)
				{
					leg = (int) cardsRank - (int) other.cardsRank;
				}
			}

			return leg;
		}

		public bool Equals(SuperCard otherCard)
		{
			bool isEqual = false;

			if (otherCard != null)
			{
				isEqual = cardSuit == otherCard.cardSuit;
			}

			return isEqual;
		}
    }
}