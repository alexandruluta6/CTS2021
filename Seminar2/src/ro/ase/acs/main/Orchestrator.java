package ro.ase.acs.main;

import ro.ase.acs.contracts.Readable;
import ro.ase.acs.contracts.Writeable;
import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;

public class Orchestrator {
	private Readable reader = new Reader();
	private Writeable writer = new ConsoleWriter();
	
	public Orchestrator(Readable reader, Writeable writer) {
		this.reader = reader;
		this.writer = writer;
	}
	
	public void execute() {
		writer.print(reader.read());
	}
}
