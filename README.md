# 🛸 Typing Speed Test (C++ Console Application)

Welcome to the **Typing Speed Test**!

This simple C++ console program measures how fast and how accurately you can type a randomly selected sentence. It displays a friendly ASCII alien, gives you a sentence, starts a timer, and then reports:

* Time taken

* Words Per Minute (WPM)

* Accuracy

* Average results across multiple rounds

Perfect for practicing beginner-level C++ concepts like strings, vectors, references, timing, loops, and raw string literals.

## 👽 Project Preview

```text
   .-.
  (o o)        _____________
   |=|        | Let's Type! |
  __|__       ------------- 
 /     \       
/_______\
```

## Features

* **Randomly selects** a sentence from a predefined list.

* **Measures typing time** using `<chrono>`.

* Calculates:

  * **Words Per Minute (WPM)** using the standard 5-characters-per-word formula.

  * **Character-level accuracy**.

* Prevents reuse of sentences during a session.

* Stores all results and prints overall averages.

* Fun ASCII alien & friendly CLI experience.

* Clean C++ fundamentals with:

  * `vector`

  * `string`

  * raw string literals (`R"( ... )"`)

  * references (`const string&`)

  * `std::chrono` for timing

## Learning Objectives

This project helps you practice:

### C++ Basics

* Input/output with `std::cout`, `std::getline`

* Control flow (`while`, `if`, `for`)

* Functions with reference parameters

### Standard Library

* `std::vector`

* `std::string`

* `std::find`

* `std::chrono` timing tools

### Software Concepts

* Random sentence selection

* Accuracy measurement

* WPM calculation

* Aggregating results across runs

* User-driven program loops

## How It Works

1. The program displays instructions and the ASCII alien.

2. It waits for you to press **Enter** to begin.

3. A random sentence is shown.

4. A timer starts the moment you begin typing.

5. After you press **Enter**:

   * The timer stops.

   * Your input is compared to the original.

   * Accuracy and WPM are calculated.

6. You can repeat as many times as you’d like.

7. When finished, the program shows your average WPM and accuracy.


## WPM Formula

This program uses the standard typing-test definition:

> **1 word = 5 characters** > **WPM = (characters / 5) ÷ minutes**

In code:

```cpp
wpm = (typed.length() / 5.0) / (timeTaken / 60.0);
```

## Example Output

```text
Type the following sentence:
"Practice makes perfect, so keep on typing!"

Time Taken: 6.41 seconds
Words Per Minute (WPM): 62.37
Accuracy: 95.8%
Do you want to try again? (y/n):
```
