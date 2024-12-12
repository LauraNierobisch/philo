void* routine()
{
	printf("Test from threads\n");
}
int main(int argc, char *argv[])
{
	pthread_t t1;
	// Funktion zum creieren von einem thread
	//           variable, NULL, Funktion die wir includen wollen, argument das wir in die funktion einbringen wollen
	pthread_create(&t1, NULL, &routine, NULL);
	//funktion die macht das der thread wartet
	pthread_join(t1, NULL);
	return(0);
	// Alles was man braucht ist eine variable in einem Struct, pthread_create, pthread_join und man hat ein struct.
}