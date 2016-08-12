/*

*/

void encrypt(char *msg){

	while(*msg){

		*msg = *msg ^ 31;
		msg++;
	}


}