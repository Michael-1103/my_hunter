/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** int_to_str
*/

void reverse_str(char *str, int length)
{
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void int_to_str(int num, char *str)
{
    int i = 0;

    if (num == 0) {
        str[i] = '0';
        i++;
        str[i] = '\0';
        return;
    }
    while (num != 0) {
        str[i] = (num % 10) + '0';
        i++;
        num = num / 10;
    }
    str[i] = '\0';
    reverse_str(str, i);
}
