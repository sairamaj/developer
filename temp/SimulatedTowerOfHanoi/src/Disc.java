
public class Disc {
	private int size;
	
	Disc(int size){
		this.size = size;
	}
	
	int getSize() {
		return this.size;
	}
	
	void draw() {
		for(int i=0; i<this.size; i++) {
			System.out.print("_");
		}
		System.out.println("");
	}
}
