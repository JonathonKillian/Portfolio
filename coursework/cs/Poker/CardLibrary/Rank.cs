namespace CardLibrary
{
	public enum Rank
	{
		// Pip cards are worth their pip count
		Deuce =  2,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		// Face cards continue the increment from 11 to 14
		Jack,
		Queen,
		King,
		// Aces are only considered high in this program.
		Ace
	}
}
