/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


/* prototypes */
void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool card_exists[NUM_RANKS][NUM_SUITS]);
void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool card_exists[NUM_RANKS][NUM_SUITS], bool *royal_p, bool *straight_p, bool *flush_p, bool *four_p, bool *three_p, int *pairs_p);
void print_result(bool *royal_p, bool *straight_p, bool *flush_p, bool *four_p, bool *three_p, int *pairs_p);

int main(void) {
    bool royal, straight, flush, four, three;
    bool *royal_p = &royal, *straight_p = &straight, *flush_p = &flush, *four_p = &four, *three_p = &three;
    int pairs; // can be 0, 1, or 2
    int *pairs_p = &pairs; // can be 0, 1, or 2
    
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    bool card_exists[NUM_RANKS][NUM_SUITS];
    for (;;) {
        read_cards(num_in_rank, num_in_suit, card_exists);
        analyze_hand(num_in_rank, num_in_suit, card_exists, royal_p, straight_p, flush_p, four_p, three_p, pairs_p);
        print_result(royal_p, straight_p, flush_p, four_p, three_p, pairs_p);
    }
}

void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool card_exists[NUM_RANKS][NUM_SUITS]) {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    // create an array containing bool to indicate if a card exists
    for (rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++) {
            card_exists[rank][suit] = false;
        }
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }
        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;
        
        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card; ignored.\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool card_exists[NUM_RANKS][NUM_SUITS], bool *royal_p, bool *straight_p, bool *flush_p, bool *four_p, bool *three_p, int *pairs_p) {
    int num_consec = 0;
    int rank, suit;
    int initial_rank;
    *royal_p = true;
    *straight_p = false;
    *flush_p = false;
    *four_p = false;
    *three_p = false;
    *pairs_p = 0;

    /* check for royal (check if there is only t, j, q, k, a in the cards and card starts from rank t) */
    for (int rank = 0; rank < 8; rank ++) {
        if (num_in_rank[rank] != 0) {
            *royal_p = false;
            break;
        }
    }
    if (*royal_p == true) {
        if (num_in_rank[8] == 0)
            *royal_p = false;
    }

    /* check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            *flush_p = true;

    /* check for straight */
    rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    initial_rank = rank;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS) {
        *straight_p = true;
        return;
    }
    else if ((initial_rank == 0) && (num_consec = 4) && (num_in_rank[12] > 0)) {
        *straight_p = true;
        return;
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) *four_p = true;
        if (num_in_rank[rank] == 3) *three_p = true;
        if (num_in_rank[rank] == 2) *pairs_p++;
    }
}

void print_result(bool *royal_p, bool *straight_p, bool *flush_p, bool *four_p, bool *three_p, int *pairs_p) {
    if ((*royal_p && *flush_p) && *straight_p)
        printf("royal flush");
    else if (*straight_p && *flush_p)
        printf("Straight flush");
    else if (*four_p)
        printf("Four of a kind");
    else if (*three_p && *pairs_p == 1)
        printf("Full house");
    else if (*flush_p)
        printf("Flush");
    else if (*straight_p)
        printf("Straight");
    else if (*three_p)
        printf("Three of a kind");
    else if (*pairs_p == 2)
        printf("Two pairs");
    else if (*pairs_p == 1)
        printf("pair");
    else
        printf("High card");
        
    printf("\n\n");
}