// Define a class Word Example having the followingdescription:
// Data members/instance variables:
// private String strdata: to store a sentence.
// Parameterized Constructor WordExample(String) : Accept a
// sentence which
// may be terminated by either’.’, ‘? ’or’!’ only. The wordsmay be separated by
// more than one blank space and are in UPPER CASE.
// Member Methods:
// void countWord(): Find the number of wordsbeginning and
// ending with a vowel.
// void placeWord(): Place the words which begin andend with a vowel at the
// beginning, followed by the remaining words as they occur in the sentence

import java.util.Scanner;

class WordExample {
  private String strdata;

  public WordExample(String str) { this.strdata = str; }

  public void countWord() {
    String[] words = strdata.split(" ");
    int count = 0;
    for (String word : words) {
      if (word.length() > 0) {
        char firstChar = word.charAt(0);
        char lastChar = word.charAt(word.length() - 1);
        if (isVowel(firstChar) && isVowel(lastChar)) {
          count++;
        }
      }
    }
    System.out.println("Number of words beginning and ending with a vowel: " +
                       count);
  }

  public void placeWord() {
    String[] words = strdata.split(" ");
    StringBuilder result = new StringBuilder();
    StringBuilder vowels = new StringBuilder();
    StringBuilder consonants = new StringBuilder();
    for (String word : words) {
      if (word.length() > 0) {
        char firstChar = word.charAt(0);
        char lastChar = word.charAt(word.length() - 1);
        if (isVowel(firstChar) && isVowel(lastChar)) {
          vowels.append(word).append(" ");
        } else {
          consonants.append(word).append(" ");
        }
      }
    }
    result.append(vowels).append(consonants);
    System.out.println("Result: " + result.toString());
  }

  private boolean isVowel(char c) {
    return "AEIOU".indexOf(Character.toUpperCase(c)) != -1;
  }
}

public class Exp11 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a sentence: ");
    String sentence = sc.nextLine();

    WordExample wordExample = new WordExample(sentence);
    wordExample.countWord();
    wordExample.placeWord();
  }
}
