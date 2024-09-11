import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.util.Collections;
import java.io.Serializable;

/*
- Sublcass of Publication
- implements printable
*/
public class Journal extends Publication{
    protected String mEditor;
    protected int mIssueNumber;


    // Default Constructor
    // Calls the default constructor of the Publication class
    // initializes the member variables of the journal class
    public Journal(){
        super();
        mEditor = " ";
        mIssueNumber = 0;
    }
    // Overloaded Constructor
    // Calls the overloaded constructor of the Publication class
    // Initializes the variables with the values given by the peramters
    public Journal(String title, int yearOfPublication, String publisher, long isbn, String editor, int issueNumber){
        super(title,yearOfPublication,publisher,isbn);
        mEditor = editor;
        mIssueNumber = issueNumber;
    }

    // The getters and setters
    // Uses to modify and get the member variables of the journal class
    public String getEditor(){
        return mEditor;
    }
    public int getIssueNumber(){
        return mIssueNumber;
    }

    public void setEditor(String editor){
        mEditor = editor;
    }
    public void setIssueNumber(int issueNumber){
        mIssueNumber = issueNumber;
    }

    /*
    - Defines the printable interface
    - Prints the given publication to a text file
    */
    public void print(String fileName){
        PrintWriter pw = null;
        FileWriter myFS = null;
        try{
            myFS = new FileWriter(fileName,true);
            pw = new PrintWriter(myFS);
            pw.println("Title: " + this.getTitle() + "; Year of Publication: " + this.getYearOfPublication() + "; Publisher: " + 
            this.getPublisher() + "; ISBN: " + this.getISBN() + "; Editor: " + this.getEditor() + "; Issue Number: " + this.getIssueNumber());
        }
        catch(IOException ioex){
            System.err.println(ioex.getMessage());
        }
        pw.close();
    }

    // Allows the Journal class to be expressed in the form of a string
    public String toString(){
        return "Title: " + getTitle() + "; Year of Publication: " + getYearOfPublication() + "; Publisher: " + getPublisher() + "; ISBN: " + getISBN() +
        "; Editor: " + getEditor() + "; Issue Number: " + getIssueNumber();
    }

}