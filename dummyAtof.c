#include <stdio.h>
#include <ctype.h>

/** 
 * Dummy atof function: Converts the string 's' to a double.
 * 
 * This function converts a string representation of a floating-point number to its double equivalent.
 * It skips leading whitespaces, handles the sign, and interprets both the integer and fractional parts.
 * 
 * Parameters:
 * @param s: The input string to be converted to a double.
 * 
 * Returns:
 * @return The equivalent double value of the input string.
 * 
 * Note:
 * - This is a simplified/dummy version of the atof function of the stlib.h atof function and it does not handle all possible edge cases or it may not be suitable for all scenarios
 *   It is labeled as 'dummy' to indicate its basic functionality
 */
 
double atof(char s[]) {
    double val, power;
    int i, sign;

    // Skip leading whitespaces
    for (i = 0; isspace(s[i]); i++)
        ;

    // Determine the sign of the number
    sign = (s[i] == '-') ? -1 : 1;

    // Skip sign characters if present
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Process the integer part of the number
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Process the fractional part of the number
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    // Return the final double value, taking into account the sign and decimal point
    return sign * val / power;
}
