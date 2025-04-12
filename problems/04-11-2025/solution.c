bool isSymetric(int n) {
    int digits[100];
    int length= 0;

    while (n > 0) {
        digits[length++] = n % 10;
        n /= 10;
    }

    if (length % 2 != 0) return false;

    int leftSide = 0, rightSide = 0;;
    for (int i = 0; i < length / 2; i++) {
        leftSide += digits[i];
    }

    for (int i = length / 2; i < length; i++) {
        rightSide += digits[i];
    }
    return leftSide == rightSide;
}



int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; i++) {
        if (isSymetric(i)) count++;
    }
    return count;
}