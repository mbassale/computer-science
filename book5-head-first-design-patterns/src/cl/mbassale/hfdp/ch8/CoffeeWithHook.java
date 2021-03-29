package cl.mbassale.hfdp.ch8;

public class CoffeeWithHook extends CaffeineBeverageWithHook {

    private boolean wantsCondiments = true;

    public CoffeeWithHook() {
    }

    public CoffeeWithHook(boolean wantsCondiments) {
        this.wantsCondiments = wantsCondiments;
    }

    @Override
    protected void brew() {
        System.out.println("Dripping Coffee through filter");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding Sugar and Milk");
    }

    @Override
    protected boolean customerWantsCondiments() {
        return wantsCondiments;
    }
}
