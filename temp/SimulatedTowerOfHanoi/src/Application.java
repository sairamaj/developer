import java.util.Scanner;
import java.util.stream.Stream;

public class Application {

	public static void main(String[] args) {
		Gamer g;
		try {
			g = new Gamer(3);
			g.create();

			Scanner in=new Scanner(System.in);
			do {
				System.out.println("From:");
				int from = in.nextInt();
				if( from == 99 ) {
					System.out.println("quitting...");
					break;
				}
				
				System.out.println("To:");
				int to = in.nextInt();
				g.move(from, to);
			} while (true);

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
