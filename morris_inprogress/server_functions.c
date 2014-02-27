char* position(char buffer)
{
	char position[3];
	position[0] = buffer[1];
	position[1] = buffer[2];
	position[2] = buffer[3];

	return position;
}

char* playerNum(char buffer)
{
	char playernum[2];
	playernum[0] = buffer[4];
	playernum[1] = buffer[5];

	return playernum;
}