int checksum(char *msg){

	int c = 0;
	while(*msg){

		c+= c ^ (int) (*msg);
		msg++;
	}

	return c;
}