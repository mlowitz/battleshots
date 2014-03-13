char* position(char buffer)
{
	char position[2];
	position[0] = buffer[2];
	position[1] = buffer[3];
	

	return position;
}

char* playerNum(char buffer)
{
	char playernum[2];
	playernum[0] = buffer[4];
	playernum[1] = buffer[5];

	return playernum;
}

char* shipNum(char buffer)
{ char* shipnum[1];
  shipnum[0]=buffer[1];
  return shipnum;
}
