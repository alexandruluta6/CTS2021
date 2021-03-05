package ro.ase.acs.writers;

import ro.ase.acs.contracts.Writeable;

public class ConsoleWriter implements Writeable {

	public void print(String message) {
		System.out.println(message);
	}

//	@Override
//	public String read() {
//		// TODO Auto-generated method stub
//		return null;
//	}
}
