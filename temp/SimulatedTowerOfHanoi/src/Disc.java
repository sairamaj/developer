
public class Disc {
	public static final String ANSI_RESET = "\u001B[0m";
	public static final String ANSI_RED = "\u001B[31m";
	
	private int size;

	Disc(int size){
		this.size = size;
	}
	
	int getSize() {
		return this.size;
	}
	
	void draw(int spacerWidth) {
		
		fillSpace(spacerWidth);
		for(int i=0; i<this.size; i++) {
			System.out.print("_");
		}
		System.out.println("");
	}
	
	void fillSpace(int spacerWidth) {
		for(int i=0; i<spacerWidth; i++) {
			System.out.print(" ");
		}
	}
}
