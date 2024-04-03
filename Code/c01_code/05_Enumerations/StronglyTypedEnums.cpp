enum class PieceType
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn
};

int main()
{
	{
		PieceType piece{ PieceType::King };

		if (piece == PieceType::King)
		{
			/* ... */
		}
	}

	{
		using enum PieceType;
		PieceType piece{ King };
	}

	{
		using PieceType::King;
		PieceType piece{ King };
		piece = PieceType::Queen;
	}
}
