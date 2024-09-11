import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.util.Collections;
import java.io.Serializable;

/*
- Sublcass of Journal
- implements printable
*/
public class EJournal extends Journal{
    protected String mURL;
    protected int mPublicationFee;

    // Default Constructor
    // Calls the default constructor of the Journal class
    // initializes the member variables of the EJournal class
    public EJournal(){
        super();
        mURL = " ";
        mPublicationFee = 0;
    }

    // Overloaded Constructor
    // Calls the overloaded constructor of the Journal class
    // Initializes the variables with the values given by the peramters
    public EJournal(String title, int yearOfPublication, String publisher, long isbn, String editor, int issueNumber, String url, int publicationFee){
        super(title,yearOfPublication,publisher,isbn, editor, issueNumber);
        mURL = url;
        mPublicationFee = publicationFee;
    }

    // The getters and setters
    // Uses to modify and get the member variables of the ejournal class
    public String getURL(){
        return mURL;
    }
    public int getPublicationFee(){
        return mPublicationFee;
    }

    public void setURL(String url){
        mURL = url;
    }
    public void setPublicationFee(int publicationFee){
        mPublicationFee = publicationFee;
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
            this.getPublisher() + "; ISBN: " + this.getISBN() + "; Editor: " + this.getEditor() + "; Issue Number: " + this.getIssueNumber() +
            "; URL: " + this.getURL() + "; Publication Fee: " + this.getPublicationFee());
        }
        catch(IOException ioex){
            System.err.println(ioex.getMessage());
        }
        pw.close();
    }

    // Allows the EJournal class to be expressed in the form of a string
    public String toString(){
        return "Title: " + getTitle() + "; Year of Publication: " + getYearOfPublication() + "; Publisher: " + getPublisher() + "; ISBN: " + getISBN() +
        "; Editor: " + getEditor() + "; Issue Number: " + getIssueNumber() + "; URL: " + getURL() + "; Publication Fee: " + getPublicationFee();
    }

}