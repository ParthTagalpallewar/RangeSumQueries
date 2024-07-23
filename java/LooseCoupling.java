interface PaymentService{
    void processPayment(double amount);
}

class CardPayment implements PaymentService{

    @Override
    public void processPayment(double amount){}
}

class PaypalPayment implements PaymentService{

    @Override
    public void processPayment(double amount){}
}

class Order{
    PaymentService paymentService;
    public Order(PaymentService paymentService){
        this.paymentService = paymentService;
    }

    public void checkout(double amount){
        paymentService.processPayment(amount);
    }
}

public class LooseCoupling {
    public static void main(String[] args) {
        PaymentService paymentService = new CardPayment(); // or new PaypalPayment()
        Order order = new Order(paymentService);
        order.checkout(100.0);
    }
}