/** 
 * Uma função auxiliar para obter o valor máximo em array[]
*/
int getMax(int array[], int len)
{
    int mx = array[0]; 
    for (int i = 1; i < len; i++) 
        if (array[i] > mx) 
            mx = array[i]; 
    return mx;
}