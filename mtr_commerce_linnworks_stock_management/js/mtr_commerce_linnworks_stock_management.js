(function ($) {
  $(document).ready(function () {

    Drupal.behaviors.ss2 = {
      attach: function (context, settings) {
     // Disable to change quantiy and price at 4G admin page
        $("input[id*='edit-field-product-und-entities']").click(function () {
          $("input[name*='commerce_price']").attr("readonly", true);
          $("input[name*='commerce_stock']").attr("readonly", true);
        });
      }};

  });

})(jQuery);
