#include <stdio.h>

struct card {
	const char *face;
	const char *suit;
};

int main()
{
	struct card aCard;
	struct card *ptrCard;

	aCard.face = "Ace";
	aCard.suit = "Spades";

	ptrCard = &aCard;

	printf("%s of %s\n", aCard.face, aCard.suit);
	printf("%s of %s\n", ptrCard->face, ptrCard->suit);
	printf("%s of %s\n", (*ptrCard).face, (*ptrCard).suit);
}