package ro.ase.acs.main;

import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;

//import java.io.IOException;
//import java.util.Scanner;
//
//import ro.ase.acs.readers.Reader;
//import ro.ase.acs.writers.ConsoleWriter;
//import ro.ase.acs.writers.FileWriter;

public class Main {

	public static void main(String[] args) {
		
//		Reader reader = new Reader();
//		FileWriter writer = new FileWriter();
//		writer.print(reader.read());
//		try {
//			reader.close();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
		
		Orchestrator orchestrator = new Orchestrator(new Reader(), new ConsoleWriter());
		orchestrator.execute();

	}

}
