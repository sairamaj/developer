
public class Application {

	public static void main(String[] args) {
		Gamer g;
		try {
			g = new Gamer(1);
			g.create();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
