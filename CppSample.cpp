/**************************************************************
Student Name: Ghazal Erfani

Student Number: 200-442-578

Assignment Number: CS 110-001 Assignment #4

Program Name: DNAAnalysis.cpp

Date Written: 2020-04-05

Problem Statement: DNA analysis is an important part of medical exploration and
discovery.  In this C++ program, we examine both hemoglobin genes for
each of four people, with each gene consisting of 444 DNA bases
(A,C,T,G).  These are the four bases (letters) that make up DNA.

Sickle-cell anemia is a disorder that is caused by a single mutation
in the hemoglobin gene.

A sickle hemoglobin gene has a T in the 20th position.
A person is anemic if he/she has two sickle hemoglobin genes.
A person is a carrier if he/she has one sickle hemoglobin gene.
Otherwise, the person is normal.

Include a subfunction, called SameGene, that takes two characters arrays and their size,
and returns true if they are the same gene; and returns false, otherwise.

Thanks to Dr. John Stavrinides in the Biology Department for creating this question.
"What's so beautiful about DNA is that its turned Biology
into a kind of branch of Computer Science"
Richard Dawkins, former biologist at Oxford University and a fellow of the Royal Society, in The Genius of Charles Darwin.

Input: The input file, called dna.txt and found on UR Courses, contains the DNA of
the two hemoglobin genes of four people. The file contains the gene DNA
information in this order:
geneA1
geneA2
geneB1
geneB2
geneC1
geneC2
geneD1
geneD2
where 1 and 2 denote the first and second gene, and A,B,C,D denote people.
The required information is found in the first 3552 characters of dna.txt,
that is, there is no whitespace before or between the eight genes.

Output: A report file, called DNAanalysis.txt, that indicates whether each person
is anemic, a carrier, or normal. For example,
Person X is anemic.
Person Y is normal.
Person Z is a carrier.

Two individuals are related if they share at least one gene.
The output determines whether any of the above four individuals are relate in DNAanalysis.txt. For example,
Person X is related to person Y.


Main algorithm:	Write a value returning function (boolean), called isSickleHemoglobin, that takes a character array and the size of the array
					and check whether the gene has a "T" in the 20th position of DNAs or not.
				Write a value returning function (string), called typeOfThePerson, that takes two genes (arrays) of a person and the array size
					and check whether this person is anemic, carrier, or normal.
				Write a value returning function, called SameGene, that takes 2 character arrays and the size of them and check whether they are the same or not.
				Write a value returning function, called isRelated, that takes 4 character arrays (2 genes of 2 people) and the size of them and check whether these two people are related or not.

				Having isSickleHemoglobin, typeOfThePerson, and SameGene above:
					Try to open the input and output files.
					Error check the opening of input and output files.
					Check to make sure the input characters are one of (A, G, C, T)
					Take the characters of each genes from the input and save them to separated arrays.
					Write type of the people with using <typeOfThePerson>  function.
						<typeOfThePerson> uses <isSickleHemoglobin> to check whether the person is anemic, carrier, or normal.
					Write related people with using <isRelated> function.
						<isRelated> function uses <SameGene> function to check whether two genes are the same or not.




Major Variables: NUMBER_OF_DNAs - the number of DNAs in one gene  (constant integer)
				 TPosition - the position of T in gene (constant integer)
				 geneA1[] - first gene of the person A (array of characters)
				 geneA2[] - second gene of the person A (array of characters)
				 geneB1[] - first gene of the person B (array of characters)
				 geneB2[] - second gene of the person B (array of characters)
				 geneC1[] - first gene of the person C (array of characters)
				 geneC2[] - second gene of the person C (array of characters)
				 geneD1[] - first gene of the person D (array of characters)
				 geneD2[] - second gene of the person D (array of characters)

Assumptions: - Sickle-cell anemia is a disorder that is caused by a single mutation
			   in the hemoglobin gene.
			 - A sickle hemoglobin gene has a T in the 20th position.
			 - A person is anemic if he/she has two sickle hemoglobin genes.
			   a person is a carrier if he/she has one sickle hemoglobin gene.
			   Otherwise, the person is normal.

Program Limitations: - This program inputs only 4 people's gene.
					 - The characters of each gene should be uppercase. This program does not convert lowercase letters to uppercase.
					 - This program takes only 2 sequence of DNAs for two genes of a person.
					 - This program only checks the type of a person (anemic, carrier, normal) and the relation between people.
					 - This program does not check whether the gene is exists in a real world or not.


**************************************************************/

#include <iostream>		// for I/O
#include <fstream>		// for file I/O

using namespace std;

// functions prototype
/**
 * Check whether the gene is a sickle hemoglobin gene
 *
 * This function takes a character array and the size of the array and check whether the gene has a "T" in the 20th position of DNAs or not
 *
 * @param[in] gene[] The characters in the gene
 * @param[in] arraySize The size of the array
 * @returns a boolean value whether the gene is a sickle hemoglobin
 */
bool isSickleHemoglobin(const char gene[], int arraySize, int tPosition);

/**
 * Find the type of the person
 *
 * This function takes two genes (arrays) of a person and the array size and check whether this person is anemic, carrier, or normal
 *
 * @param[in] gene1[], gene2[] Two sequences of genes
 * @param[in] arraySize The size of the arrays
 * @returns a string whether it is anemic, carrier, or normal
 */
string typeOfThePerson(const char gene1[], const char gene2[], int arraySize, int tPosition);



/**
 * Check the euquality of two genes
 *
 * This function takes 2 character arrays and the size of them and check whether they are the same or not
 *
 * @param[in] gene1[], gene2[] Two sequences of genes
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether two genes or the same or not
 */
bool SameGene(const char gene1[], const char gene2[], int arraySize);

/**
 * Check relation between 2 people
 *
 * This function takes 4 character arrays (2 genes of 2 people) and the size of them and check whether these two people are related or not
 *
 * @param[in] geneX1[], geneX2[] Two sequences of person X genes
 * @param[in] geneY1[], geneY2[] Two sequences of person Y genes
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether two people are related or not
 */
bool isRelated(const char geneX1[], const char geneX2[], const char geneY1[], const char geneY2[], int arraySize);

/**
 * Check whether the input is correct or not
 *
 * This function takes a character array (gene) and the size of it and check whther it is a valid input or not
 *
 * @param[in] gene[] The characters in the gene
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether the input is valid or not
 */
bool isValid(const char gene[], int arraySize);


// declare the number of DNAs in one gene (NUMBER_OF_DNAs) and the position of T in genes (TPosition) as a global constant integer
const int NUMBER_OF_DNAs = 444, TPosition = 19;


int main()
{	////////// Declare variables ////////////

	
	// declare geneA1 and geneA2 as an integer array (the size of these arrays are one character more than
	//...NUMBER_OF_DNAs in order to store \0 by the get function below).
	char geneA1[NUMBER_OF_DNAs + 1], geneA2[NUMBER_OF_DNAs + 1];
	// declare geneB1 and geneB2 as an integer array 
	char geneB1[NUMBER_OF_DNAs + 1], geneB2[NUMBER_OF_DNAs + 1];
	// declare geneC1 and geneC2 as an integer array 
	char geneC1[NUMBER_OF_DNAs + 1], geneC2[NUMBER_OF_DNAs + 1];
	// declare geneD1 and geneD2 as an integer array 
	char geneD1[NUMBER_OF_DNAs + 1], geneD2[NUMBER_OF_DNAs + 1];

	/////////// Declare input and output buffers/////////
	// declare inFile as an input buffer 
	ifstream inFile;
	// declare outFile as an output buffer
	ofstream outFile;

	//////////// Open input and ouptut files /////////////
	// try to open the input file, called <dna.txt>
	inFile.open("dna.txt");
	// error check the file open
	if (!inFile)
	{
		// print an error message
		cout << "Error opening the input file, <dna.txt>" << endl;
		// end the program with error code 1
		return 1;
	}

	// try to open the output file, called <DNAanalysis.txt>
	outFile.open("DNAanalysis.txt");
	// error check the file open
	if (!outFile)
	{
		// print and error message
		cout << "Error opening the output file, <DNAanalysis.txt>" << endl;
		// end the program with error code 2
		return 2;
	}

	////////// Get the characters of each genes ////////////

	//the size of these arrays are one character more than
	//...NUMBER_OF_DNAs in order to store \0 by the get function below
	// get the first gene of the person A
	inFile.get(geneA1, NUMBER_OF_DNAs + 1);
	// get the second gene of the person A
	inFile.get(geneA2, NUMBER_OF_DNAs + 1);
	// get the first gene of the person B
	inFile.get(geneB1, NUMBER_OF_DNAs + 1);
	// get the second gene of the person B
	inFile.get(geneB2, NUMBER_OF_DNAs + 1);
	// get the first gene of the person C
	inFile.get(geneC1, NUMBER_OF_DNAs + 1);
	// get the second gene of the person C
	inFile.get(geneC2, NUMBER_OF_DNAs + 1);
	// get the first gene of the person D
	inFile.get(geneD1, NUMBER_OF_DNAs + 1);
	// get the second gene of the person D
	inFile.get(geneD2, NUMBER_OF_DNAs + 1);

	// check the input whether it is valid or not
	if (!isValid(geneA1, NUMBER_OF_DNAs) || !isValid(geneA2, NUMBER_OF_DNAs) || !isValid(geneB1, NUMBER_OF_DNAs) || !isValid(geneB2, NUMBER_OF_DNAs) || !isValid(geneC1, NUMBER_OF_DNAs) || !isValid(geneC2, NUMBER_OF_DNAs) || !isValid(geneD1, NUMBER_OF_DNAs) || !isValid(geneD2, NUMBER_OF_DNAs))
	{
		// print the error message
		cout << "The input is invalid. It should contain only letters A, T, C, and G";
		// end the program with error code 3
		return 3;	
	}

	/////////// Write the results /////////////

	// write the type of the person A in the <DNAanalysis.txt>
	outFile << "Person A is " << typeOfThePerson(geneA1, geneA2, NUMBER_OF_DNAs, TPosition) << "." << endl;
	// write the type of the person B in the <DNAanalysis.txt>
	outFile << "Person B is " << typeOfThePerson(geneB1, geneB2, NUMBER_OF_DNAs, TPosition) << "." << endl;
	// write the type of the person C in the <DNAanalysis.txt>
	outFile << "Person C is " << typeOfThePerson(geneC1, geneC2, NUMBER_OF_DNAs, TPosition) << "." << endl;
	// write the type of the person D in the <DNAanalysis.txt>
	outFile << "Person D is " << typeOfThePerson(geneD1, geneD2, NUMBER_OF_DNAs, TPosition) << "." << endl;

	
	/////////// Write the related people /////////////
	if (isRelated(geneA1, geneA2, geneB1, geneB2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person A is related to person B
		outFile << "Person A is related to person B." << endl;
	if (isRelated(geneA1, geneA2, geneC1, geneC2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person A is related to person C
		outFile << "Person A is related to person C." << endl;
	if (isRelated(geneA1, geneA2, geneD1, geneD2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person A is related to person D
		outFile << "Person A is related to person D." << endl;
	if (isRelated(geneB1, geneB2, geneC1, geneC2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person B is related to person C
		outFile << "Person B is related to person C." << endl;
	if (isRelated(geneB1, geneB2, geneD1, geneD2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person B is related to person D
		outFile << "Person B is related to person D." << endl;
	if (isRelated(geneC1, geneC2, geneD1, geneD2, NUMBER_OF_DNAs))
		// write in the <DNAanalysis.txt> that person C is related to person D
		outFile << "Person C is related to person D." << endl;

	inFile.close();
	outFile.close();

	return 0;		// end the program
}

/**
 * Check whether the input is correct or not
 *
 * This function takes a character array (gene) and the size of it and check whther it is a valid input or not
 *
 * @param[in] gene[] The characters in the gene
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether the input is valid or not
 */
bool isValid(const char gene[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (gene[i] != 'A' && gene[i] != 'C' && gene[i] != 'T' && gene[i] != 'G')
			return false;
	}
	return true;
}

/**
 * Check whether the gene is a sickle hemoglobin gene
 *
 * This function takes a character array and the size of the array and check whether the gene has a "T" in the 20th position of DNAs or not
 *
 * @param[in] gene[] The input gene is stored in this array
 * @param[in] arraySize The size of the array
 * @returns a boolean value whether the gene is a sickle hemoglobin
 */
bool isSickleHemoglobin(const char gene[], int arraySize, int tPosition)
{
	// if there is a "T" in the 20th position
	if (gene[TPosition] == 'T')
		return true;		// return true to say that there is a "T" in the 20th position of the gene
	// if there is no "T" in the 20th position 
	else
		return false;		// return false to say that there is no "T" in the 20th position of the gene
}

/**
 * Find the type of the person
 *
 * This function takes two genes (arrays) of a person and the array size and checks whether this person is anemic, carrier, or normal
 *
 * @param[in] gene1[], gene2[] Two sequences of genes
 * @param[in] arraySize The size of the arrays
 * @returns a string whether he/she is anemic, carrier, or normal
 */
string typeOfThePerson(const char gene1[], const char gene2[], int arraySize, int tPosition)
{
	// declare a boolean variable, called isSickleHemoglobin1, to save into it whether gene1 is sickle hemoglobin (true) or not (false)
	bool isSickleHemoglobin1 = isSickleHemoglobin(gene1, arraySize, tPosition);
	// declare a boolean variable, called isSickleHemoglobin2, to save into it whether gene2 is sickle hemoglobin (true) or not (false)
	bool isSickleHemoglobin2 = isSickleHemoglobin(gene2, arraySize, tPosition);
	// if both genes are sickle hemoglobin
	if (isSickleHemoglobin1 && isSickleHemoglobin2)
		return "anemic";		// the person is anemic
	// if one of the genes is sickle hemoglobin
	else if (isSickleHemoglobin1 || isSickleHemoglobin2)
		return "carrier";		// the person is carrier
	// if none of the genes are sickle hemoglobin
	else
		return "normal";		// the person is normal
}


/**
 * Check the euquality of two genes
 *
 * This function takes 2 character arrays and the size of them and check whether they are the same or not
 *
 * @param[in] gene1[], gene2[] Two sequences of genes
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether two genes or the same or not
 */
bool SameGene(const char gene1[], const char gene2[], int arraySize)
{
	//I found three ways to do this comparison. I commented the two that does not need arraySize and uses string and C_String


	///////Solution 1 using C++ strings///////
	/*string g1 = gene1; //Converting C_Strings (char array with \0 at the end) to string to use string comparison
	string g2 = gene2;

	return (g1 == g2);//Using string comparison to compare two strings
	*/
	//////////	

	///////Solution 2 using C_Strings (Chapter 7 of the book, table 7.1)///////
	//return (strcmp(gene1, gene2)==0);


	/////////////Solution 3 using char arrays comparision and arraysize////////////
	// declare a boolean variable <isSame> to save whether two genes are the same (true) or not (false) and initialize it as true.
	bool isSame = true;
	// for the number of the characters in the array do the following:
	for (int i = 0; i < arraySize; i++)
	{
		// check whether the i th character of the genes are the same
		if (gene1[i] != gene2[i])
		{
			// if they are not the same, then these two genes are not the same. so, set <isSame> into false
			isSame = false;
			// go out of the for loop
			break;
		}
	}
	// return <isSame> value, whether the two genes are the same (true) or not (false)
	return isSame;
}

/**
 * Check relation between 2 people
 *
 * This function takes 4 character arrays (2 genes of 2 people) and the size of them and check whether these two people are related or not
 *
 * @param[in] geneX1[], geneX2[] Two sequences of person X genes
 * @param[in] geneY1[], geneY2[] Two sequences of person Y genes
 * @param[in] arraySize The size of the arrays
 * @returns a boolean value whether two people are related or not
 */
bool isRelated(const char geneX1[], const char geneX2[], const char geneY1[], const char geneY2[], int arraySize)
{
	if (SameGene(geneX1, geneY1, arraySize) || SameGene(geneX1, geneY2, arraySize) || SameGene(geneX2, geneY1, arraySize) || SameGene(geneX2, geneY2, arraySize))
		return true;
	else
		return false;
}
