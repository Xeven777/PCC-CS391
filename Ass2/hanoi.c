// tower of hanoi using recursion in c

#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }

  tower_of_hanoi(n - 1, source, auxiliary, destination);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  tower_of_hanoi(n - 1, auxiliary, destination, source);

  return;
}

int main() {
  int n = 0;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  tower_of_hanoi(n, 'A', 'C', 'B');

  return 0;
}
