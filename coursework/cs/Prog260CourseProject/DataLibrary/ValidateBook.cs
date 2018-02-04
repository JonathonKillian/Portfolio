using System;

namespace BookLibrary {
	// All book properties must be non-blank & not whitespace-only
	// Rating is a single digit/character & pubyear is a ranged numerical value
	public static class ValidateBook {
		// While not part of the Book object, it is directly related, so
		// validating it here fits.
		public static bool ISBN(string isbn) {
			int number;

			return IsPresent(isbn) &&
				int.TryParse(isbn, out number) &&
				number > 0;
		}

		public static bool Title(string title) {
			return IsPresent(title);
		}

		public static bool Author(string author) {
			return IsPresent(author);
		}

		// Rating is from '1' (poor) to '5' (great)
		public static bool Rating(string rating) {
			const char POOR  = '1';
			const char GREAT = '5';

			return IsPresent(rating) &&
				rating.Length == 1 &&
				rating[0] >= POOR && rating[0] <= GREAT;
		}

		// This method is just so the other methods can portray
		// positive boolean
		private static bool IsPresent(string text) {
			return !string.IsNullOrWhiteSpace(text);
		}

		// Year must be an integer, 4 digits and not a future year.
		public static bool PubYear(string pubYear) {
			// Per Wikipedia, this is the earliest printing milestone
			// https://en.wikipedia.org/wiki/History_of_books
			const int MIN_YEAR = 1377;
			int year;
			int maxYear = DateTime.Now.Year;		// No future printed books

			return IsPresent(pubYear) &&
				int.TryParse(pubYear, out year) &&
				year >= MIN_YEAR && year <= maxYear;
		}
	}
}
