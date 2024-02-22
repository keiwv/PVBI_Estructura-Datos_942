

// Persona
int valid(char msge[], int ri, int rf);

int valid(char msge[], int ri, int rf)
{
    int op;
    char array[40];
    int result;

    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);

        result = sscanf(array, "%d", &op);

        if (result != 1 || op < ri || op > rf)
        {
            op = -1;
        }

    } while (op == -1);

    return op;
}
