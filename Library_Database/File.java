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
// This class handles all cases involving files and storing information to the disk
*/
public class File{

    // This class asks the user if they wish to serialize
    // If they choose yes
        // The program will open a serializable file on the disk titled "database.ser" and put that information into the hashmap that the program will use in the prompt class
    // If they choose no
        // this method will do nothing and return the haspmap with no modifications
    public static HashMap<Long, Publication> serilize(HashMap<Long, Publication> myDatabase){
        Scanner ser = new Scanner(System.in);
        System.out.println("Do you have an existing Library? ");
        System.out.println("1) yes");
        System.out.println("2) no");
        int check = Integer.parseInt(ser.nextLine());
        HashMap<Long, Publication> temp;
        if (check == 1){
            try {
                FileInputStream fileIn = new FileInputStream("database.ser");
                ObjectInputStream in = new ObjectInputStream(fileIn);
                temp = (HashMap<Long, Publication>) in.readObject();
                in.close();
                fileIn.close();
                for (Map.Entry<Long, Publication> entry: temp.entrySet()){
                    myDatabase.put(entry.getKey(),entry.getValue());
                }
            } catch (IOException i) {
                i.printStackTrace();
            } catch (ClassNotFoundException j) {
                System.out.println("Class not found");
                j.printStackTrace();
            }
        }
        return myDatabase;
    }

    /*
    // This method asks the user to enter a isbn 
    // It will then ask what file name you wish to send the publication you selected to
    // After that the publication will be sent to said file with all of its contents displayed in the file
    */
    public static void sendToFile(HashMap<Long, Publication> myDatabase){
        Scanner userIsbn = new Scanner(System.in);
        System.out.println("\nEnter the ISBN of the Publication");
        long isbn = Long.parseLong(userIsbn.nextLine());
        System.out.println("Enter the file name to print to");
        String fName = userIsbn.nextLine();
        Publication add = myDatabase.get(isbn);
        add.print(fName);
    }

    /*
    // This method reads in a csv file that is storing information that could be used for a publication
    // It will read the file and write its contents into a list
    // Then it will iterate through the list and create book publications with the contents of the list
    // These book publications are put into the hashmap
    */
    public static HashMap<Long,Publication> importDataFromFile(String csvFile,HashMap<Long,Publication> myDatabase) throws IOException{
        FileInputStream fis = new FileInputStream(csvFile);
        Scanner br = new Scanner(fis);
        String line;
        List<String[]> data = new ArrayList<String[]>();
        while (br.hasNext()) {
            line = br.nextLine();
            StringTokenizer st = new StringTokenizer(line,",");
            String[] row = new String[st.countTokens()];
            int i = 0;
            while (st.hasMoreTokens()) {
                row[i++] = st.nextToken();
            }
            data.add(row);
        }
        br.close();
        for (String[] row : data) {
            String title = row[0];
            int yearPub = Integer.parseInt(row[1]);
            String publisher = row[2];
            long ISBN = Long.parseLong(row[3]);
            String author = row[4];
            int numPag = Integer.parseInt(row[5]);
            String bind = row[6];

            myDatabase.put(ISBN,new Book(title,yearPub,publisher,ISBN,author,numPag,bind));
        }
        System.out.println("import complete");
        return myDatabase;
    }

    /*
    // This method deserilizes the contents of the hashmap to the disk
    // It stores the publication objects that you have created and placed into the hashmap
    // This way when you start up the program again, you can serialize and still have all of the previously made publications
    */
    public static void deserilize(HashMap<Long,Publication> myDatabase){
        FileOutputStream fileOut = null;
        ObjectOutputStream out = null;
        try{
            fileOut = new FileOutputStream("database.ser");
            out = new ObjectOutputStream(fileOut);
            out.writeObject(myDatabase);
            out.close();
            fileOut.close();
        } catch(IOException ioex){
            System.err.println(ioex.getMessage());
        }
        System.out.println("Database Saved");
    }
}