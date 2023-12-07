#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	const char *face;
	const char *suit;
} Card;

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle(Card *const wDeck);
void deal(const Card *const wDeck);

int main()
{
	Card deck[52];

	const char *face[13] = {
		"Ace", "Deuce", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "King", "Queen"
	};
	const char *suit[4] = {
		"Hearts", "Diamonds",
		"Clubs", "Spades"
	};

	srand(time(NULL));

	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
}

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[])
{
	for (int i = 0; i < 52; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}

void shuffle(Card *const wDeck)
{
	Card tmp;
	for (int i = 0; i < 52; i++) {
		int t = rand() % 52;
		tmp = wDeck[i];
		wDeck[i] = wDeck[t];
		wDeck[t] = tmp;
	}
}

void deal(const Card *const wDeck)
{
	for (int i = 0; i < 52; i++) {
		printf("%5s of %-8s%s",
			wDeck[i].face, wDeck[i].suit,
			(i + 1) % 4 ? " " : "\n");
	}
}