import static java.lang.System.in;
import static java.lang.System.out;


class Main {

    static int checkDigit(int checksum) {
	return (10 - checksum % 10) % 10;
    }

    static int multiplyIsbnDigit(int digit, int position) {
	if (position % 2 == 0) return 3 * (digit - '0');
	else return digit - '0';
    }

    public static void main(String[] args) throws java.io.IOException {
	int position = 1; // valid positions [1, 12]
	int checksum = 0;
	int digit; // will store values in range [0,255]

	while ((digit = in.read()) != '\n') {
	    if (digit != ' ' && digit != '-') {
		if (position < 13) {
		    checksum += multiplyIsbnDigit(digit, position);
		}
		position++;
	    }
	}

	if (position != 13) {
	    out.print("The number is not valid. The code must be 12 digits long.\n");
	} else {
	    out.print("The check digit is: " + checkDigit(checksum) + ".\n");
	}
    }
}
