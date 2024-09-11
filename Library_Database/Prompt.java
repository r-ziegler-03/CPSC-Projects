import java.util.HashMap;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.io.Serializable;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.util.StringTokenizer;
import java.util.List;


/*
// This class handles the prompts of the program
// Asks the user what they want to do when the program runs
// Executes the users input
*/
public class Prompt{

    // When the program first starts the user is prompted with these questions
    public static void promptUser(){
        System.out.println("1) Add A Publication to the Library");
        System.out.println("2) Print Publication to File");
        System.out.println("3) Print All Publications by Publication Date");
        System.out.println("4) Delete a publication from the Library");
        System.out.println("5) Import Default Library");
        System.out.println("6) EXIT");
    }

    // This method creates a Book publication
    // This method is run when the user chooses to add a publication and chooses to add a book
    public static HashMap<Long, Publication> type1(HashMap<Long, Publication> myDatabase){
        Scanner book = new Scanner(System.in);
        System.out.println("\n Enter Title: ");
        String title = book.nextLine();
        System.out.println("Enter the Year of Publication: ");
        int publicationYear = Integer.parseInt(book.nextLine());
        System.out.println("Enter the Publisher: ");
        String publisher = book.nextLine();
        System.out.println("Enter the ISBN: ");
        long bisbn = Long.parseLong(book.nextLine());
        System.out.println("Enter the Author: ");
        String author = book.nextLine();
        System.out.println("Enter the Number of Pages: ");
        int numPages = Integer.parseInt(book.nextLine());
        System.out.println("Enter the Bind Type (hardback or paperback): ");
        String bindType = book.nextLine();
        myDatabase.put(bisbn,new Book(title,publicationYear, publisher, bisbn, author, numPages, bindType));
        return myDatabase;
    }

    // This method creates a Journal publication
    // This method is run when the user chooses to add a publication and chooses to add a Journal
    public static HashMap<Long, Publication> type2(HashMap<Long, Publication> myDatabase){
        Scanner journal = new Scanner(System.in);
        System.out.println("\nEnter Title: ");
        String title = journal.nextLine();
        System.out.println("Enter the Year of Publication: ");
        int publicationYear = Integer.parseInt(journal.nextLine());
        System.out.println("Enter the Publisher: ");
        String publisher = journal.nextLine();
        System.out.println("Enter the ISBN: ");
        long jisbn = Long.parseLong(journal.nextLine());
        System.out.println("Enter the Editor: ");
        String editor = journal.nextLine();
        System.out.println("Enter the Issue Number: ");
        int issueNumber = Integer.parseInt(journal.nextLine());
        myDatabase.put(jisbn,new Journal(title,publicationYear, publisher, jisbn, editor, issueNumber));
        return myDatabase;
    }

    // This method creates a EJournal publication
    // This method is run when the user chooses to add a publication and chooses to add a EJournal
    public static HashMap<Long, Publication> type3(HashMap<Long, Publication> myDatabase){
        Scanner ejournal = new Scanner(System.in);
        System.out.println("\nEnter Title: ");
        String title = ejournal.nextLine();
        System.out.println("Enter the Year of Publication: ");
        int publicationYear = Integer.parseInt(ejournal.nextLine());
        System.out.println("Enter the Publisher: ");
        String publisher = ejournal.nextLine();
        System.out.println("Enter the ISBN: ");
        long eisbn = Long.parseLong(ejournal.nextLine());
        System.out.println("Enter the Editor: ");
        String editor = ejournal.nextLine();
        System.out.println("Enter the Issue Number: ");
        int issueNumber = Integer.parseInt(ejournal.nextLine());
        System.out.println("Enter the URL: ");
        String url = ejournal.nextLine();
        System.out.println("Enter the Publication Fee: ");
        int pubFee = Integer.parseInt(ejournal.nextLine());
        myDatabase.put(eisbn,new EJournal(title,publicationYear, publisher, eisbn, editor, issueNumber, url, pubFee));
        return myDatabase;
    }

    // This method prints the title and year of publication to the terminal
    // The terminal list the publications that have been added, sorted by date
    // oldest date to newest date
    public static void printDescendingOrder(HashMap<Long, Publication> myDatabase){
        ArrayList<Publication> convert = new ArrayList<Publication>();
        for (Map.Entry<Long, Publication> entry: myDatabase.entrySet()){
            convert.add(entry.getValue());
        }
        Collections.sort(convert);
        for (Publication pubs: convert){
            System.out.println("Title: " + pubs.getTitle() + "; Year of Publication: " + pubs.getYearOfPublication() + "\n");
        }
    }

    // This method removes a publication object from the hashmap collection
    // The user chooses which to delete by entering the isbn
    public static void removePublication(HashMap<Long, Publication> myDatabase){
        Scanner remove = new Scanner(System.in);
        System.out.println("Enter the ISBN: ");
        long search = remove.nextLong();
        myDatabase.remove(search);
        System.out.println("Successfully removed");
    }

    // This is the method that continues to execute the program until the user chooses to exit
    // It will call certain methods that were defined above depending on the options they input
    public static void inDatabase(Scanner scanner, HashMap<Long, Publication> myDatabase){
        int choice = scanner.nextInt();
        while(choice != 6){
            switch(choice){
                case 1:
                    Scanner type = new Scanner(System.in);
                    System.out.println("\n1) Book");
                    System.out.println("2) Journal");
                    System.out.println("3) E-Journal");
                    int pubType = type.nextInt();
                    if (pubType == 1){
                        Prompt.type1(myDatabase);
                    } else if (pubType == 2){
                        Prompt.type2(myDatabase);
                    } else if (pubType == 3){
                        Prompt.type3(myDatabase);
                    } else {
                        System.out.println("Invalid Input");
                    }
                    break;
                case 2: 
                    File.sendToFile(myDatabase);
                    break;
                case 3:
                    Prompt.printDescendingOrder(myDatabase);
                    break;
                case 4:
                    Prompt.removePublication(myDatabase);
                    break;
                case 5:
                    try{
                        File.importDataFromFile("random_data.csv",myDatabase);
                    } catch(IOException ioex){
                        System.err.println(ioex.getMessage());
                    }
            }
            Prompt.promptUser();
            choice = scanner.nextInt();
        }
        File.deserilize(myDatabase);
    }
}