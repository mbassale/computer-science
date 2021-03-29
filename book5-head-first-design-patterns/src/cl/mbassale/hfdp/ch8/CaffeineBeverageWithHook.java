package cl.mbassale.hfdp.ch8;

public abstract class CaffeineBeverageWithHook {

    public final void prepareRecipe() {
        boilWater();
        brew();
        pourInCoup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

    protected abstract void brew();

    protected abstract void addCondiments();

    protected void boilWater() {
        System.out.println("Boiling water");
    }

    protected void pourInCoup() {
        System.out.println("Pouring into cup");
    }

    protected boolean customerWantsCondiments() {
        return true;
    }
}
