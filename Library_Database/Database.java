import java.io.Serializable;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Collections;
import java.util.ArrayList;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.ObjectInputStream;


/*
 - The runner file
*/
public class Database
{
    /* main method
    // throws IOException in case of input/output errors
    // Declares the Hashmap collection that will hold the publications
    // Decalres a scanner object to take user input
    // Calls methods from the File and Prompt class that handle different aspects of the program
    */
    public static void main(String[]argv) throws IOException{
        HashMap<Long, Publication> myDatabase = new HashMap<>();
        File.serilize(myDatabase);
        Scanner scanner = new Scanner(System.in);
        Prompt.promptUser();
        Prompt.inDatabase(scanner, myDatabase);
    }

}
