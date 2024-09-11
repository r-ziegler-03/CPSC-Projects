import java.util.Collections;
import java.util.HashMap;  
import java.util.Map;  
import java.io.Serializable;


/*
- Parent class for Books,Journals, and E-Journals
- Uses the printable interface which prints the objects
- Uses the comparabel interface which compares objects by their year of publication and sorts them
- Uses the Serializable interface to store the objects to the disk
*/
public abstract class Publication implements Printable, Comparable<Publication>, Serializable {
    protected String mTitle;
    protected int mYearOfPublication;
    protected String mPublisher;
    protected long mISBN;
    private static final long serialVersionUID = 1L;


    // Deault Constructor
    public Publication(){
        mTitle = " ";
        mYearOfPublication = 0;
        mPublisher = " ";
        mISBN = 0L;
    }

    // Overloaded Constructor
    public Publication(String title, int yearOfPublication, String publisher, long isbn){
        mTitle = title;
        mYearOfPublication = yearOfPublication;
        mPublisher = publisher;
        mISBN = isbn;
    }

    /*
     - Getters and Setters to modify the member variables
    */
    public void setTitle(String title){
        mTitle = title;
    }
    public void setYearOfPublication(int yearOfPublication){
        mYearOfPublication = yearOfPublication;
    }
    public void setPublisher(String publisher){
        mPublisher = publisher;
    }
    public void setISBN(long isbn){
        mISBN = isbn;
    }

    public String getTitle(){
        return mTitle;
    }
    public int getYearOfPublication(){
        return mYearOfPublication;
    }
    public String getPublisher(){
        return mPublisher;
    }
    public long getISBN(){
        return mISBN;
    }

    // Allows the Publication object to be expressed in the form of a string
    public String toString(){
        return "Title: " + getTitle() + "; Year of Publication: " + getYearOfPublication() + "; Publisher: " + getPublisher() + "; ISBN: " + getISBN();
    }

    // Abstract, will be defined in the subclasses, book, journal, e-journal
    // Uses the custom printable interface
    @Override
    public abstract void print(String fileName);

    /*
    - Uses the comparable interface
    - Compares two publication objects
    1. If their year of publication is equal it returns 0
    2. If this object's year of publication is greater than the publication in the perameter, 1 is returned
    3. If this object's year of publication is less than the publication in the perameter, -1 is returned
    */
    @Override
    public int compareTo(Publication pub){ 
        if (this.getYearOfPublication() == pub.getYearOfPublication()){
            return 0;
        } else if (this.getYearOfPublication() > pub.getYearOfPublication()){
            return 1;
        } else {
            return -1;
        }
    }
   
}