public class Lr12Koni {
    public static void main(String[] args) {
        Jacket jacket = new Jacket("Nike", "L", "Black");
        Shirt shirt = new Shirt("Adidas", "M", "White");
        Pants pants = new Pants("Puma", "L", "Blue");
        Shoes shoes = new Shoes("Reebok", "42", "Brown");

        jacket.chooseClothing();
        shirt.chooseClothing();
        pants.chooseClothing();
        shoes.chooseClothing();
        System.out.println();
        jacket.wear();
        shirt.wear();
        pants.wear();
        shoes.wear();
    }
}
