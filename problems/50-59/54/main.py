from collections import Counter
from typing import Iterable

'''
In the card game poker, a hand consists of five cards and are ranked, from 
lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:

2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest 
value wins; for example, a pair of eights beats a pair of fives (see example 1 
below). But if two ranks tie, for example, both players have a pair of queens, 
then highest cards in each hand are compared (see example 4 below); if the 
highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

The file, poker.txt, contains one-thousand random hands dealt to two players. 
Each line of the file contains ten cards (separated by a single space): the 
first five are Player 1's cards and the last five are Player 2's cards. You can 
assume that all hands are valid (no invalid characters or repeated cards), each 
player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?
'''

# has the rank and the suit
class Card:
    def __init__(self, name: str):
        self.suit: str = name[-1]
        self.rank: int = self.get_rank(name[0:-1])

    def get_rank(self, rankstr: str) -> int:
        if rankstr == "T": return 10
        elif rankstr == "J": return 11
        elif rankstr == "Q": return 12
        elif rankstr == "K": return 13
        elif rankstr == "A": return 14
        else: return int(rankstr)

    def __lt__(self, other) -> bool:
        return False


class Hand: 
    def __init__(self, cards: list[Card]):
        self.cards: list[Card] = cards
        handrank, rank, handhighcard = self.evaluate_hand()
        self.handrank: int = handrank
        self.rank: int = rank
        self.hand_high_card: int = handhighcard

    def __eq__(self, other) -> bool: 
        highcard_eq = self.hand_high_card == other.hand_high_card
        rank_eq = self.rank == other.rank
        handrank_eq = self.handrank == other.handrank
        return highcard_eq and rank_eq and handrank_eq

    def __lt__(self, other) -> bool:
        if self.handrank != other.handrank:
            return self.handrank < other.handrank
        elif self.rank != other.rank:
            return self.rank < other.rank
        else:
            return self.hand_high_card < other.hand_high_card

    
    def evaluate_hand(self) -> tuple[int, int, int]:
        handrank_finder_fns = [
            has_royal_flush, has_straight_flush, has_four_of_a_kind, 
            has_full_house, has_flush, has_straight, has_three_of_a_kind, 
            has_two_pair, has_one_pair, highcard]

        handrank_values = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

        for handrank, handrank_finder in zip(handrank_values, handrank_finder_fns):
            rank, remaining_cards = handrank_finder(self.cards)
            if rank != 0:
                handhighcard, _ = highcard(remaining_cards)
                return handrank, rank, handhighcard


# Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
def has_royal_flush(cards: list[Card]):
    flush_rank, _ = has_flush(cards)
    straight_rank, _ = has_straight(cards)
    if flush_rank != 0 and straight_rank == 14:
        return straight_rank, []
    else: 
        return 0, cards;


# Straight Flush: All cards are consecutive values of same suit.
def has_straight_flush(cards: list[Card]):
    flush_rank, _ = has_flush(cards)
    straight_rank, _ = has_straight(cards)
    if flush_rank != 0 and straight_rank != 0:
        return straight_rank, []
    else:
        return 0, cards
        

def has_four_of_a_kind(cards: list[Card]):
    counter = Counter([card.rank for card in cards])
    # print(counter)
    for rank, count in counter.items():
        if count == 4:
            return rank, [c for c in cards if c.rank != rank]
    return 0, cards


# Full House: Three of a kind and a pair.
def has_full_house(cards: list[Card]): 
    top_rank, remaining_cards = has_three_of_a_kind(cards)
    bottom_rank, _ = has_three_of_a_kind(remaining_cards)
    if top_rank != 0 and bottom_rank != 0:
        return top_rank, []
    else:
        return 0, cards


# Flush: All cards of the same suit.
def has_flush(cards: list[Card]):
    suit = cards[0].suit
    for card in cards:
        if suit != card.suit: return 0, cards
    return max([card.rank for card in cards]), []


# Straight: All cards are consecutive values.
def has_straight(cards: list[Card]):
    counter = Counter([card.rank for card in cards])
    # print(counter)
    if max(counter.values()) == 1:
        if max(counter.keys()) - min(counter.keys()) == 4:
            return max(counter.keys()), []

        elif max(counter.keys()) == 14:
            card_ranks = [card.rank for card in cards if card.rank != 14]  + [1]
            if max(card_ranks) - min(card_ranks) == 4:
                return max(card_ranks), []
    return 0, cards


# Three of a Kind: Three cards of the same value.
def has_three_of_a_kind(cards: list[Card]):
    counter = Counter([card.rank for card in cards])
    # print(counter)
    for rank, count in counter.items():
        if count == 3:
            return rank, [c for c in cards if c.rank != rank]
    return 0, cards


# Two Pairs: Two different pairs.
def has_two_pair(cards: list[Card]): 
    first_rank, remaining_cards = has_one_pair(cards)
    second_rank, last_card = has_one_pair(remaining_cards)
    if second_rank != 0:
        return max(first_rank, second_rank), last_card
    else:
        return 0, cards


# One Pair: Two cards of the same value.
def has_one_pair(cards: list[Card]):
    counter = Counter([card.rank for card in cards])
    # print(counter)
    for rank, count in counter.items():
        if count == 2:
            return rank, [c for c in cards if c.rank != rank]
    return 0, cards


# High Card: Highest value card.
def highcard(cards: list[Card]):
    if len(cards) == 0: return 0, []
    return max([card.rank for card in cards]), []
    


with open("/Users/gregszumel/Documents/coding/project_euler/problems/50-59/54/0054_poker.txt") as f:
    lines = f.readlines()

counter = 0
for line in lines:
    all_cards = line.split("\n")[0].split(" ")
    all_cards = [Card(card) for card in all_cards]
    p1 = Hand(all_cards[:5])
    p2 = Hand(all_cards[5:])
    # print(p1.handrank, p1.rank, p1.hand_high_card)
    # print(p2.handrank, p2.rank, p2.hand_high_card)
    # print(p1 < p2)
    # print("------------")
    if p1 > p2: counter += 1

print(counter)
