/******************************************************************************
* Course: PROG 110
* Instructor: S. Unwin
* Term: Fall 2015
*
* Solution/Project Name: KillianRandomSol/KillianHW6
* File Name: GuessNumber.cs
*
* This file defines the entry point method for the Console application.
*
* Programmer: Jon Killian
* Assigned Homework Number: Homework 6 (HW6)
*
* Revision Date Release Comment
* -------- ---------- ------------------------------------------------------
* 1.0      11/10/2015 Initial Release
*
* Class Name & Purpose (Description)
* GuessNumber
* ---------------
* Have the User guess a number between 1 and 50 in a "game show" like
* atmosphere, replete with "textual sounds." The User will not be told which
* direction (too low/too high) to the number, but the range of valid numbers
* will be shortened upon their incorrect guess.
*
******************************************************************************/
using System;

namespace KillianHW6
{
	class GuessNumber
	{
		static void Main()
		{
			const int MIN_RANGE = 1;
			const int MAX_RANGE = 50;
			const int RESET_COUNT = 0;
			const string BANNER_SPACE = "                             ";
			const string BANNER_LINE = 
				BANNER_SPACE + "######################\n";
			const string GUESS_PROMPT =
				"Contestant, please enter your guess from the range " +
				"of {0} to {1}: ";
			const string YES_PLAY = "yes";
			const string NO_PLAY = "no";
			const string ANOTHER_ROUND = 
				"\n\nContestant, shall we play again (" + YES_PLAY +
				"," + NO_PLAY + "): ";
			int countGuess = RESET_COUNT;
			int userGuess = 0;
			int minGuess = MIN_RANGE;
			int maxGuess = MAX_RANGE;
			int winningNumber = 0;
			string playAgain = YES_PLAY;
			Random random = new Random();

			// Display introduction
			Console.WriteLine(
				"Welcome back to another round of \"Guess that number!\"\n\n" +
				"For those tuning in for the first time, let me go over the " +
				"rules.\n" +
				"A random number between 1 and 50 will be generated.\n" +
				"The contestant will continue making guesses within the " +
				"valid range until they\n" +
				"find the number. It's that simple folks!\n" +
				"Do I hear you cry that how could the contestant guess the " +
				"number with no clues\n" +
				"but incorrect guesses? We won't leave them in the lurch, " +
				"folks! Every incorrect\n" +
				"guess will shorten their valid range of choices!\n\n" +
				"Ladies and gentlemen, are you all ready for today's " +
				"contestant? Then let's all\ngive a warm welcome as the " +
				"contestant comes on stage! Clap, clap, clap\n\n" +
				"We've generated some numbers through our patent pending " +
				"process, we have our\nContestant, the audience is all " +
				"jived up. We are ready to begin!\n");

			// Start the round
			do
			{
				// Generate the winning number
				winningNumber = random.Next(MIN_RANGE, MAX_RANGE+1);

				// Start the round and prompt user for a number
				Console.Write(
					"The winning number is now locked. " +
					"Contestant, get ready to play...\n\n" + BANNER_LINE +
					BANNER_SPACE + "# Guess that number! #\n" + BANNER_LINE +
					"\n" + GUESS_PROMPT, minGuess, maxGuess);
				int.TryParse(Console.ReadLine(), out userGuess);

				// Validate the guess
				while (userGuess != winningNumber)
				{
					// Keep track of the guesses
					++countGuess;

					// Did the user guess too far out?
					if (userGuess < minGuess || userGuess > maxGuess)
					{
						// Think about the sound of a buzzer
						Console.WriteLine(
							"BUZZZ! Your guess is outside the valid range of " +
							"{0} to {1} and needs to be a whole\n" +
							"number. Please keep track of the valid range " +
							"and try again.\n", minGuess, maxGuess);
					}
					else
					{
						// Think sad trombone, https://youtu.be/iMpXAknykeg
						Console.WriteLine(
							"Wah wah wah. I'm sorry, your guess is " +
							"incorrect, please try again.\n");

						// Adjust the range and exclude the current guess
						if (userGuess < winningNumber)
						{
							minGuess = ++userGuess;
						}
						else
						{
							maxGuess = --userGuess;
						}
					}

					// Prompt User for another guess
					Console.Write(
						"Contestant, please enter your guess from the range " +
						"of {0} to {1}: ", minGuess, maxGuess);
					int.TryParse(Console.ReadLine(), out userGuess);
				}

				// Still need to count the guess, even if it's winning
				++countGuess;

				// Congrat the User! With a bell even. And then prompt to play
				// another round, validating their answer.
				Console.Write(
					"Ding ding ding ding! Ladies and gentlemen, we have a " +
					"winner!\n" +
					"Our contestant was able to find the number in {0} " +
					"guesses.\n" + ANOTHER_ROUND, countGuess);
				playAgain = Console.ReadLine().ToLower();
				while (playAgain != YES_PLAY && playAgain != NO_PLAY)
				{
					Console.Write(
						"I'm sorry, but your response was lost in the " +
						"cheering.\n" +
						/*"Could you try again with a \"" + YES_PLAY +
						"\" or \"" + NO_PLAY + "\"?" +*/ ANOTHER_ROUND);
					playAgain = Console.ReadLine().ToLower();
				}
				// If User wants to play again, set up for a new round
				if (playAgain == YES_PLAY)
				{
					Console.Clear();
					minGuess = MIN_RANGE;
					maxGuess = MAX_RANGE;
					countGuess = RESET_COUNT;

				}
			} while (playAgain == "yes");

			// Display closing message and program end message
			Console.Write(
				"\n\nContestant, thank you for playing!\n" +
				"Ladies and gentlemen, let's give another round of " +
				"applause to our fine\n" +
				"Contestant as they leave the stage. Clap, clap, clap.\n\n" +
				"Thank you for watching \"Guess that number!\"\n" + 
				"Please tune in again to watch our next contestant and don't" + 
				" forgot " + 
				"about our\nhome game!\n\n\n\n\n" +
				"The program has now gone off the air. " +
				"Press a key to close the window.");
			// wait for User keypress
			Console.ReadKey();
		}
	}
}
