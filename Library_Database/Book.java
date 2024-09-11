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
public class Book extends Publication implements Printable{
    protected String mAuthor;
    protected int mNumPages;
    protected String mBindType;

    // Default Constructor
    // Calls the default constructor of the Publication class
    // initializes the member variables of the book class
    public Book(){
        super();
        mAuthor = " ";
        mNumPages = 0;
        mBindType = " ";
    }

    // Overloaded Constructor
    // Calls the overloaded constructor of the Publication class
    // Initializes the variables with the values given by the peramters
    public Book(String title, int yearOfPublication, String publisher, long isbn, String author, int pages, String bindType){
        super(title,yearOfPublication,publisher,isbn);
        mAuthor = author;
        mNumPages = pages;
        mBindType = bindType;
    }

    // The getters and setters
    // Uses to modify and get the member variables of the book class
    public String getAuthor(){
        return mAuthor;
    }
    public int getPages(){
        return mNumPages;
    }
    public String getBindType(){
        return mBindType;
    }

    public void setAuthor(String author){
        mAuthor = author;
    }
    public void setPages(int pages){
        mNumPages = pages;
    }
    public void setBindType(String bindType){
        mBindType = bindType;
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
            this.getPublisher() + "; ISBN: " + this.getISBN() + "; Author: " + this.getAuthor() + "; Number of Pages: " +
            this.getPages() + "; Bind type: " + this.getBindType());
        }
        catch(IOException ioex){
            System.err.println(ioex.getMessage());
        }
        pw.close();
    }

    // Allows the Book class to be expressed in the form of a string
    public String toString(){
        return "Title: " + getTitle() + "; Year of Publication: " + getYearOfPublication() + "; Publisher: " + getPublisher() + "; ISBN: " + getISBN() + "; Author: " + getAuthor() +
        "; Number of Pages: " + getPages() + "; Bind type: " + getBindType();
    }

}