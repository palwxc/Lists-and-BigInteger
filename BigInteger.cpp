//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 03/19/2018
//File: BigInteger.cpp			//Description: Defines functions for BigInteger.h

#include "BigInteger.h"

//using namespace std;

void get_identity(std::string my_id[]);

void get_identity(std::string my_id[])
{
    my_id[0]="palwxc";
    my_id[1]="12398940";
}

//<=
bool greaterEqualString(std::string leftString, std::string rightString);

bool greaterEqualString(std::string leftString, std::string rightString)
{
    bool leftStringisNegative=false, rightStringisNegative=false;
    //gets ride of '-' in string, makes note of presence
    if(leftString[0]=='-')
    {
        leftStringisNegative=true;
        //cout << "bi1 is " << bi1.to_string() << " and is negative" << endl;
        leftString.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(rightString[0]=='-')
    {
        rightStringisNegative=true;
        //cout << "bi2 is " << bi2.to_string() << " and is negative" << endl;
        rightString.erase(0,1);
    }
    //if left is negative and right is positive
    if(leftStringisNegative && !rightStringisNegative)
        return true;
    //if left is positive and right is negative
    if(!leftStringisNegative && rightStringisNegative)
        return false;
    //if both positive
    if(!rightStringisNegative)
    {
        //right is longer
        if(leftString.length()<rightString.length())
            return true;
        //left is longer
        if(leftString.length()>rightString.length())
            return false;
        for(unsigned int i=0; i<leftString.length(); i++)
        {
            if(leftString.at(i)==rightString.at(i)){}
            else if(leftString.at(i)<rightString.at(i))
                return true;
            else
                return false;
        }
    }
    //if both negative
    if(rightStringisNegative)
    {
        //right is longer
        if(leftString.length()<rightString.length())
            return false;
        //left is longer
        if(leftString.length()>rightString.length())
            return true;
        for(unsigned int i=0; i<leftString.length(); i++)
        {
            if(leftString.at(i)==rightString.at(i)){}
            else if(leftString.at(i)<rightString.at(i))
                return false;
            else
                return true;
        }
    }
    //both are same sign and same string
    return true;
}

//<
bool greaterString(std::string leftString, std::string rightString);

bool greaterString(std::string leftString, std::string rightString)
{
    bool leftStringisNegative=false, rightStringisNegative=false;
    //gets ride of '-' in string, makes note of presence
    if(leftString[0]=='-')
    {
        leftStringisNegative=true;
        //cout << "bi1 is " << bi1.to_string() << " and is negative" << endl;
        leftString.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(rightString[0]=='-')
    {
        rightStringisNegative=true;
        //cout << "bi2 is " << bi2.to_string() << " and is negative" << endl;
        rightString.erase(0,1);
    }
    //if left is negative and right is positive
    if(leftStringisNegative && !rightStringisNegative)
        return true;
    //if left is positive and right is negative
    if(!leftStringisNegative && rightStringisNegative)
        return false;
    //if both positive
    if(!rightStringisNegative)
    {
        //right is longer
        if(leftString.length()<rightString.length())
            return true;
        //left is longer
        if(leftString.length()>rightString.length())
            return false;
        for(unsigned int i=0; i<leftString.length(); i++)
        {
            if(leftString.at(i)==rightString.at(i)){}
            else if(leftString.at(i)<rightString.at(i))
                return true;
            else
                return false;
        }
    }
    //if both negative
    if(rightStringisNegative)
    {
        //right is longer
        if(leftString.length()<rightString.length())
            return false;
        //left is longer
        if(leftString.length()>rightString.length())
            return true;
        for(unsigned int i=0; i<leftString.length(); i++)
        {
            if(leftString.at(i)==rightString.at(i)){}
            else if(leftString.at(i)<rightString.at(i))
                return false;
            else
                return true;
        }
    }
    //both are same sign and same string
    return false;
}


std::string addStrings(std::string bi1String, std::string bi2String);

std::string addStrings(std::string bi1String, std::string bi2String)
{
    bool bi1StringisNegative=false, bi2StringisNegative=false;

    //gets ride of '-' in string, makes note of presence
    if(bi1String[0]=='-')
    {
        bi1StringisNegative=true;
        //cout << "bi1 is " << bi1.to_string() << " and is negative" << endl;
        bi1String.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(bi2String[0]=='-')
    {
        bi2StringisNegative=true;
        //cout << "bi2 is " << bi2.to_string() << " and is negative" << endl;
        bi2String.erase(0,1);
    }

    std::string total = (bi1String.length() > bi2String.length()) ?  bi1String : bi2String;
	char carry = '0';
	int differenceInLength = abs( (int) (bi1String.size() - bi2String.size()) );

	if(bi1String.size() > bi2String.size())
		bi2String.insert(0, differenceInLength, '0'); // put zeros from left

	else// if(bi1String.size() < bi2String.size())
		bi1String.insert(0, differenceInLength, '0');


//both numbers are either positive or negative
    if((bi1StringisNegative && bi2StringisNegative) || (!bi1StringisNegative && !bi2StringisNegative))
    {
        for(int i=bi1String.size()-1; i>=0; --i)
	    {
		    total[i] = ((carry-'0')+(bi1String[i]-'0')+(bi2String[i]-'0')) + '0';

		    if(i != 0)
		    {
			    if(total[i] > '9')
			    {
				    total[i] -= 10;
				    carry = '1';
			    }
			    else
				    carry = '0';
		    }
	    }
	    if(total[0] > '9')
	    {
		    total[0]-= 10;
		    total.insert(0,1,'1');
	    }
	    if(bi1StringisNegative && bi2StringisNegative)
	        total.insert(0,1,'-');
    }


//bi1String is POSITIVE and bi2String is NEGATIVE
    else if(!bi1StringisNegative && bi2StringisNegative)
    {
        // checks if 2 is greater than 1

		bool cont=greaterString(bi1String, bi2String);
		//cout << "bi1String: " << bi1String << "  bi2String: " << bi2String << endl;

        for(int i=bi1String.length()-1; i>=0; --i)
	    {
		    if(bi1String[i] < bi2String[i])
		    {
			    bi1String[i] += 10;
			    bi1String[i-1]--;
		    }
		    total[i] = ((bi1String[i]-'0')-(bi2String[i]-'0')) + '0';
	    }
        //cout << total << endl;
		//10^n - total (to make total "positive")
		if(cont)
		{
		    //cout << "inside make positive" << endl;
		    int n=total.length();
		    std::string power;
		    power.assign(n, '0');
		    power.insert(0, 1, '1');
		    //power should be 10, 100, 1000, etc.

		    total.insert(0, 1, '0'); //prepend 0 to make total and power same length

		    for(int p=power.length()-1; p>=0; --p)
	        {
		        if(power[p] < total[p])
		        {
			        power[p] += 10;
			        power[p-1]--;
		        }
		        total[p] = ((power[p]-'0')-(total[p]-'0')) + '0';
	        }
	        // total is now power - total
		}

	    while(total[0]=='0' && total.length()!=1) // erase leading zeros
		    total.erase(0,1);

	    if(cont)
	        total.insert(0,1,'-');
    }


//bi1String is NEGATIVE and bi2String is POSITIVE
    else
    {
        //cout << "bi1String is NEGATIVE and bi2String is POSITIVE" << endl;
        // checks if 1 is greater than 2

		bool cont=greaterString(bi2String, bi1String);
		//cout << "bi1String: " << bi1String << "  bi2String: " << bi2String << endl;

        for(int i=bi1String.length()-1; i>=0; --i)
	    {
		    if(bi1String[i] > bi2String[i])
		    {
			    bi2String[i] += 10;
			    bi2String[i-1]--;
		    }
		    total[i] = ((bi2String[i]-'0')-(bi1String[i]-'0')) + '0';
	    }
        //cout << total << endl;
		//10^n - total (to make total "positive")
		if(cont)
		{
		    //cout << "inside make positive" << endl;
		    int n=total.length();
		    std::string power;
		    power.assign(n, '0');
		    power.insert(0, 1, '1');
		    //power should be 10, 100, 1000, etc.

		    total.insert(0, 1, '0'); //prepend 0 to make total and power same length

		    for(int p=power.length()-1; p>=0; --p)
	        {
		        if(power[p] < total[p])
		        {
			        power[p] += 10;
			        power[p-1]--;
		        }
		        total[p] = ((power[p]-'0')-(total[p]-'0')) + '0';
	        }
	        // total is now power - total
		}

	    while(total[0]=='0' && total.length()!=1) // erase leading zeros
		    total.erase(0,1);

	    if(cont)
	        total.insert(0,1,'-');
    }
    //cout << total << endl;
    return total;
}

std::string multiplyStrings(std::string bi1String, std::string bi2String);

std::string multiplyStrings(std::string bi1String, std::string bi2String)
{
    bool bi1StringisNegative=false, bi2StringisNegative=false;
    //gets ride of '-' in string, makes note of presence
    if(bi1String[0]=='-')
    {
        bi1StringisNegative=true;
        //cout << "bi1 is " << bi1.to_string() << " and is negative" << endl;
        bi1String.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(bi2String[0]=='-')
    {
        bi2StringisNegative=true;
        //cout << "bi2 is " << bi2.to_string() << " and is negative" << endl;
        bi2String.erase(0,1);
    }
    int num1 = bi1String.size();
    int num2 = bi2String.size();
    if (num1 == 0 || num2 == 0)
        return "0";

    int result[num1 + num2] = { };

    int indexNum1 = 0;
    int indexNum2 = 0;

    for (int i=num1-1; i>=0; i--)
    {
        int carry = 0;
        int num1 = bi1String[i] - '0';

        indexNum2 = 0;

        for (int j=num2-1; j>=0; j--)
        {
            int num2 = bi2String[j] - '0';

            int sum = num1*num2 + result[indexNum1 + indexNum2] + carry;

            carry = sum/10;

            result[indexNum1 + indexNum2] = sum % 10;

            indexNum2++;
        }

        if (carry > 0)
            result[indexNum1 + indexNum2] += carry;

        indexNum1++;
    }

    int i = num1 + num2 - 1;
    while (i>=0 && result[i] == 0)
       i--;

    if (i == -1)
       return "0";

    std::string total = "";
    while (i >= 0)
        total += std::to_string(result[i--]);

    if((!bi1StringisNegative && bi2StringisNegative) || (bi1StringisNegative && !bi2StringisNegative))
	        total.insert(0,1,'-');
    return total;
}

//
std::string divideStrings(std::string dividend, std::string divisor);

std::string divideStrings(std::string dividend, std::string divisor)
{
    std::string quotient = "0";
	//std::string dividend = bi1String;
	//::string divisor = bi2String;
	std::string tmp;

    bool dividendisNegative=false, divisorisNegative=false;

    //gets ride of '-' in string, makes note of presence
    if(dividend[0]=='-')
    {
        dividendisNegative=true;
        dividend.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(divisor[0]=='-')
    {
        divisorisNegative=true;
        divisor.erase(0,1);
    }

    //cout << "while loop is about to begin" << endl;
    //cout << dividend << "  " << divisor << endl;

    tmp=divisor;
    tmp.insert(0,1,'-');
    while(greaterEqualString(divisor, dividend))
    {
        dividend = addStrings(dividend, tmp);
	    quotient = addStrings(quotient, "1");
	    //cout << quotient << endl;
    }
	//cout << "while loop has finished" << endl;

	if((dividendisNegative && !divisorisNegative) || (!dividendisNegative && divisorisNegative))
	{
	    quotient.insert(0,1,'-');
	    return quotient;
	}

	else
	    return quotient;
}

std::string modStrings(std::string base, std::string mod);

std::string modStrings(std::string base, std::string mod)
{
    bool baseisNegative=false;
    if(base[0]=='-')
    {
        baseisNegative=true;
        base.erase(0,1);
    }
    if(mod[0]=='-')
        mod.erase(0,1);

    std::string quotient = divideStrings(base, mod);
    //cout << quotient << endl;
    std::string newBase = multiplyStrings(quotient, mod);
    newBase.insert(0,1,'-');
    //cout << newBase << endl;

    quotient=addStrings(base, newBase);
    if(baseisNegative)
        quotient.insert(0,1,'-');
    return quotient;
}

/**Constructor*/
BigInteger::BigInteger()
{
    MyList<int> digit_list;
    isNegative = false;

}


/**Parameterized Constructor*/
BigInteger::BigInteger(std::string really_big_number)
{
    unsigned int tmp=0, buffer_int;
    std::string buffer_str;
    isNegative = false;
    if(really_big_number.at(0)=='-')
    {
        //cout << really_big_number.at(0);
        isNegative = true;
        tmp++;
    }
    for(unsigned int i=tmp; i<really_big_number.length(); i++)
    {
        //cout << really_big_number.at(i);
        if(really_big_number.at(i)<'0' || really_big_number.at(i)>'9')
            throw BigIntException();
        buffer_int = really_big_number.at(i)-48;
        digit_list.push_back(buffer_int);
    }
    //cout << endl;
}

std::string BigInteger::to_string()
{
    std::string tmp = "";
    MyList<int> tmp_list = digit_list;
    tmp_list.reverse();
    char buffer_char;
    for (int i=0; i<digit_list.end(); i++)
    {
        buffer_char=tmp_list.back()+48;
        tmp_list.pop_back();
        tmp.append(1, buffer_char);
    }
    if(isNegative)
    {
        tmp.insert(0,1,'-');
        //cout << "\tNEGATIVE inside to_string" << endl;
    }
    tmp_list.~MyList();
    return tmp;
}

//true=prime
//false=not prime
bool BigInteger::is_prime()
{
    std::string str=to_string();
    if(str[0]=='-')
        str.erase(0,1);
    if(isNegative)
        return false;

    std::string test="1";
    std::string str2=divideStrings(str, "2");
    std::string result="1";
    while(greaterEqualString(test, str2))
    {
        test=addStrings(test, "1");
        result = modStrings(str, test);
        if(result == "0")
            return false;
    }
    return true;
}

/**operator+*/
BigInteger operator+(const BigInteger &bi1, const BigInteger &bi2)
{
    BigInteger bi3=bi1, bi4=bi2;
    std::string bi1String=bi3.to_string(), bi2String=bi4.to_string();
    std::string total = addStrings(bi1String, bi2String);
    return BigInteger(total);
}

/**operator-*/
BigInteger operator-(const BigInteger &bi1, const BigInteger &bi2)
{
    BigInteger bi3=bi1, bi4=bi2;
    std::string bi1String=bi3.to_string(), bi2String=bi4.to_string();
    if(bi2String[0]=='-')
    {
        //cout << "bi2 is " << bi2.to_string() << " and is negative" << endl;
        bi2String.erase(0,1);
    }
    else
    {
        bi2String.insert(0,1,'-');
    }
    BigInteger bi5(bi2String);
    BigInteger total = bi3 + bi5;
    return total;
}

/**operator**/
BigInteger operator*(const BigInteger &bi1, const BigInteger &bi2)
{
    BigInteger bi3=bi1, bi4=bi2;
    std::string bi1String=bi3.to_string(), bi2String=bi4.to_string();
    bi3.digit_list.~MyList();
    bi4.digit_list.~MyList();
    std::string total = multiplyStrings(bi1String, bi2String);
    return BigInteger(total);;
}

/**operator/*/
BigInteger operator/(const BigInteger &bi1, const BigInteger &bi2)
{
    BigInteger bi3=bi1, bi4=bi2;
    std::string dividend = bi3.to_string();
	std::string divisor = bi4.to_string();
    std::string quotient = divideStrings(dividend, divisor);
    /*
	std::string quotient = "";
	std::string dividend = bi3.to_string();
	std::string divisor = bi4.to_string();
	std::string tmp;
	std::string digit;
	std::string remainder;
	char buffer;

    bool dividendisNegative=false, divisorisNegative=false;

    //gets ride of '-' in string, makes note of presence
    if(dividend[0]=='-')
    {
        dividendisNegative=true;
        dividend.erase(0,1);
    }

    //gets ride of '-' in string, makes note of presence
    if(divisor[0]=='-')
    {
        divisorisNegative=true;
        divisor.erase(0,1);
    }
    if(greaterString(dividend, divisor))
        return BigInteger("0");
    if(divisor=="0")
    {
        cout << "ERROR - operator/: dividing by 0, returning 0" << endl;
        return BigInteger("0");
    }

    int a=0, b=divisor.length();
    tmp=dividend.substr(a,b);
    cout << tmp << " tmp" << endl;
    cout << divisor << " divisor" << endl;
    if(greaterString(tmp, divisor))
        tmp=dividend.substr(a,++b);
    cout << tmp << endl << endl;
    do{
        digit = divideStrings(tmp, divisor);
        cout << "digit \t" << digit << endl;
        quotient.append(digit);//??
        cout << "quotient \t" << quotient << endl;
        remainder = multiplyStrings(divisor, digit);
        cout << "remainder \t" << remainder << endl;

        cout << "dividend \t" << dividend << endl;
        //buffer = dividend.at(b);
        //cout << buffer << endl;
        cout << "remainder \t" << remainder << endl;
        //remainder.append(1, dividend[b]);
        remainder.insert(0,1,'-');
        cout << "tmp \t" << tmp << endl;
        cout << "remainder \t" << remainder << endl;
        tmp = addStrings(tmp, remainder);
        cout << "tmp \t" << tmp << endl;
        tmp.append(1, dividend[b]);
        cout << "tmp \t" << tmp << endl << endl;
        b++;
    }while(b<dividend.length()+1);

    cout  << "quotient " << quotient << endl;

    //cout << "while loop is about to begin" << endl;
    //cout << dividend << "  " << divisor << endl;
    */
/*
    tmp=divisor;
    tmp.insert(0,1,'-');
    while(greaterEqualString(divisor, dividend))
    {
        dividend = addStrings(dividend, tmp);
	    quotient = addStrings(quotient, "1");
	    //cout << quotient << endl;
    }
	//cout << "while loop has finished" << endl;

	if((dividendisNegative && !divisorisNegative) || (!dividendisNegative && divisorisNegative))
	{
	    quotient.insert(0,1,'-');
	    return BigInteger(quotient);
	}
	else
	    return BigInteger(quotient);
	    */
    return BigInteger(quotient);
}

/**greatest common divisor*/
BigInteger gcd(const BigInteger dividend, const BigInteger divisor)
{

    BigInteger bi1=dividend, bi2=divisor;
    //bi2 <= bi1
    std::string dd = greaterEqualString(bi2.to_string(), bi1.to_string()) ? bi1.to_string() : bi2.to_string();
    //bi1 <= bi2
    std::string ds = greaterEqualString(bi1.to_string(), bi2.to_string()) ? bi1.to_string() : bi2.to_string();
    if(dd[0]=='-')
        dd.erase(0,1);
    if(ds[0]=='-')
        ds.erase(0,1);
    while(ds != "0")
    {
        std::string r = modStrings(dd, ds);
        dd = ds;
        ds = r;
    }
    return dd;

    /*
    BigInteger bi1=dividend, bi2=divisor;
    std::string dd = bi1.to_string();
    std::string ds = bi2.to_string();
    if(dd[0]=='-')
        dd.erase(0,1);
    if(ds[0]=='-')
        ds.erase(0,1);
    if(ds!="0")
        gcd(BigInteger(ds), BigInteger(modStrings(dd, ds)));
    else
        return dd;
    */
}

/**greatest efficient exponent*/
BigInteger gefficient_exp(const BigInteger base, long long power)
{
    if(power<0)
        return gefficient_exp(BigInteger("1")/base, -power);
    else if(power==0)
        return BigInteger("1");
    else if(power==1)
        return base;
    else if (power%2 == 0)
        return gefficient_exp(base * base, power/2);
    else if (power%2 != 0)
        return base * gefficient_exp(base*base, (power-1)/2);
}

