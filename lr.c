#include"lr.h"
#include<stdio.h>
#define K 3
#define NN 4
double r(int n,double e, double s, double i, int sing) {
if (i > n) { // ���� ����� �������� �������� ������ ��������� ����� ��������� n
return s; // ���������� ����� ����
}
double a = (i + 2) / (i * (i + 1)); // ��������� ������� ������� ����
//printf("a=%f\n", a);
if (a < e) { // ���� ������� ������� �������� ������ ������, �� ������� �� ��������
return s; // ���������� ����� ����
}
s = s + a * sing; // ��������� ������� ������� � ����� � ������ �����
return r(n,e, s, i + 1, -sing); // ����������� ����� ������� ��� ���������� �������� � ����������� �����������
}
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
int partition(int arr[][NN], int low, int high) {
int pivot = arr[low / NN][low % NN];
int i = low;
int j = high + 1;
while (1) {
do {
++i;
} while (arr[i / NN][i % NN] < pivot && i <= high);
do {
--j;
} while (arr[j / NN][j % NN] > pivot && j >= low);
if (i >= j)
break;
swap(&arr[i / NN][i % NN], &arr[j / NN][j % NN]);
}
swap(&arr[low / NN][low % NN], &arr[j / NN][j % NN]);
return j;
}
void quicksort(int arr[][NN], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quicksort(arr, low, pi - 1);
quicksort(arr, pi + 1, high);
}
}
int findMostSignificantOnePosition(long long N) {
    int position = 0;

    // ��������� ������ ��� ������� � ������ ��������
    while (N > 0) {
        N >>= 1; // �������� ����� �� ���� ��� ������
        position++; // ����������� �������
    }

    return position;
}

int lab1()
{
float V1, V2, t, S, V11, V21; // ����������� ���������� scanf ("%f", &V1) ;
scanf("%f", &V2) ;
scanf("%f", &t);
V11= V1*10/36; //������� �� ��/� � �/� V21=V2*10/36;
S=((V11+V21) *t)/2;
printf ("%f", S);
return 0;
}

int lab11()
{
const int a=10, b=36;
float V1, V2, t, S, V11, V21; // ����������� ���������� scanf ("%f", &V1) ;
scanf("%f", &V2) ;
scanf("%f", &t);
V11= V1*a/b; //������� �� ��/� � �/� V21=V2*a/b;
S= ((V11+V21) *t)/2;
printf ("%f", S); return 0;
}

int lab2()
{
    double s, a, i;
    int n, sing;
    printf("n="); // ����� ��������� ����
    scanf("%d", &n);
    s=0;
    i=1;
    sing=1;
    while (i<=n)
    {
        a = (i+2) / (i*(i+1));
        s=s+a*sing;
        i = i+1;
        sing = -sing;
    }
    printf("s=%f\n", s);
    return 0;
}
int lab21()

 {
int n;
double e;
double result;
printf("n="); // ����� ��������� ����
scanf("%d", &n); // ���� ����� ���������
printf("e="); // ����� ������
scanf("%lf", &e); // ���� ����� ������
result = r(n,e, 0, 1, 1); // ����� ����������� ������� ��� ���������� ����� ����
printf("s=%f\n", result); // ����� ����������
return 0;
}

int lab3()
{
char input[100]; // ���������� ������� �������� 100 ��������
int count = 0; // ���������� �������� ���-�� ���� � �������
int z = 0; // ������������ ���������� �� ������� ����� � �������
printf("������� ������: "); //�������� �����
fgets(input, sizeof(input), stdin); // ������� ���������� � ����������� � ������
for(int i=0;input[i]!='\0';i++){
if ((input[i] == ' ' || input[i] == '\n') && z) //���� ������� ������ �������� �������� ��� �������� ����� ������
//� ���������� ����� ���������� � ������� �����
{
count++; //����������� ������� count �� 1
z = 0; //���������� ����
} else if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
//���� ������� ������ �������� ������� ������ (a, e, i, o, u)
{
z = 1; //������������� ���� � 1.
}
} printf("���������� ����, ������������ � ������� �����: %d\n", count); //�����
return 0; //���������� ������� main
}
int lab4()
{
char input[100];
char output[100];
int wordCount = 0;
printf("������� ������: ");
fgets(input, sizeof(input), stdin);
int i = 0, j = 0;
int isWord = 0;
while (input[i] != '\0') {
if (input[i] != ' ' && input[i] != '\n') {
if (!isWord) {
wordCount++;
isWord = 1;
}
if (wordCount % 2 != 0) {
output[j] = input[i];
j++;
}
} else {
isWord = 0;
output[j] = input[i];
j++;
}
i++;
}
output[j] = '\0';
printf("���������: %s\n", output);
return 0;
}

int lab41()
{
char input[100];
char output[100];
int wordCount = 0;
printf("������� ������: ");
fgets(input, sizeof(input), stdin);
int i = 0, j = 0;
int isWord = 0;
int wordContainsL = 0;
while (input[i] != '\0') {
if (input[i] != ' ' && input[i] != '\n') {
if (!isWord) {
wordCount++;
isWord = 1;
wordContainsL = 0;
}
if (input[i] == 'l' || input[i] == 'L') {
wordContainsL = 1;
}
if ((wordCount % 2 != 0) || wordContainsL) {
output[j] = input[i];
j++;
}
} else {
isWord = 0;
output[j] = input[i];
j++;
}
i++;
}
output[j] = '\0';
printf("���������: %s\n", output);
return 0;
}

int lab5()
{
int arr[10] = {5, -50, 8, -10, 7, -27, 4, 7, -22, 9
};
int max = arr[0];
// ������� ������������ ������� � �������
for (int i = 1; i < 10; i++) {
if (arr[i] > max) {
max = arr[i];
}
}
// ����� ������������� �������� �� ������������ �������
for (int i = 0; i < 10; i++) {
if (arr[i] < 0) {
arr[i] /= max;
}
}
// ������� ���������� ������
printf("���������� ������:\n");
for (int i = 0; i < 10; i++) {
printf("%d ", arr[i]);
}
return 0;
}
int lab51()
{
int arr[10] = {1, -2, 3, -4, 5, -6, 7, 8, -9, 10};
int max = arr[0];
int fl=0;
// ������� ������������ ������� � �������
for (int i = 1; i < 10; i++) {
if (arr[i] > max) {
max = arr[i];
}
if (abs(arr[i-1]) > abs(arr[i])) {
fl++;
}
}
// ����� ������������� �������� �� ������������ �������
if (fl>0) {
for (int i = 0; i < 10; i++) {
if (arr[i] < 0) {
arr[i] /= max;
}}
}
// ������� ���������� ������
printf("���������� ������:\n");
for (int i = 0; i < 10; i++) {
printf("%d ", arr[i]);
}
return 0;
}
int lab6()
{
int x[K][NN]; // ������ �� K �� N ���������
int min, sum, sum_str;
// ���� �������
for( int i = 0; i < K; i++ )
for( int j = 0; j < NN; j++ )
scanf("%d", &x[i][j]);
// ���������� ������ � ����������� ������ ���������
min = 0;
sum = 0;
for( int i = 0; i < K; i++) {
sum_str=0;
for( int j = 0; j < NN; j++) {
sum_str += x[i][j];
}
if (i == 0 || sum_str < sum) {
min = i;
sum = sum_str;
}
}
// ���������� ������ � ������������ ������ ���������
int max;
sum = 0;
for( int i = 0; i < K; i++) {
sum_str=0;
for( int j = 0; j < NN; j++) {
sum_str += x[i][j];
}
if (i == 0 || sum_str > sum) {
max = i;
sum = sum_str;
}
}
// ������ ������ �������
int temp;
for (int j = 0; j < NN; j++) {
temp = x[min][j];
x[min][j] = x[max][j];
x[max][j] = temp;
}
// ������� ���������� ������
for( int i = 0; i < K; i++ ) {
for( int j = 0; j < NN; j++ )
printf("%d ", x[i][j]);
printf("\n");
}
return 0;
}
int lab61 ()
{
int x[K][NN]; // ������ �� K �� N ���������
// ���� �������
for (int i = 0; i < K; i++)
for (int j = 0; j < NN; j++)
scanf("%d", &x[i][j]);
// ���������� �������
quicksort(x, 0, K * NN - 1);
// ����� ���������������� �������
printf("��������������� ������:\n");
for (int i = 0; i < K; i++) {
for (int j = 0; j < NN; j++) {
printf("%d ", x[i][j]);
}
printf("\n");
}
return 0;
}
int lab7 (){
    long long N;
    printf("������� ������� ����� ����� N: ");
    scanf("%lld", &N);

    int position = findMostSignificantOnePosition(N);
// ��������� � �������� ��������� ������� ����� ����� N � ������� ������� ������� ������� � ��� �������� �������������, �.�. ������� ������� ������ �������� (���������� ����) �������������� ���� � ����� N
    printf("������� ������� ������� � ����� N: %d\n", position);

    return 0;
}
