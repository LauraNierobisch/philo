int main(int argc, char *argv[])
{
	if(argc == 5)
	{
		checking_arg(argc, &argv);
	}
}
int checking_arg(int argc, char *argv[])
{
	if(!ft_isdigit(argv[1]))
	{
		printf("Error: only numbers for number of Philosophers please!");
		return(1);
	}
	if(argv[1] > 200)
	{
		printf("Error: only numbers under 200 please!");
		return(1);
	}
	

}