<?php

/**
 *
 * POST Create Order
 *
 * */
function _mtr_services_linnworks_addnewuserendpoint($user_data) {

  watchdog("mtr_services_addnewuserend", json_encode($user_data));

  // user data checking..
  // email checking..

  try {
    $guid = getGUID("short");
    $guid = "";

    $response = [
      "Error" => null,
      "AuthorizationToken" => $guid,
    ];
    $output = json_encoded_response($response);
  }
  catch (Exception $e) {
    $output = _mtr_services_linnworks_error();
    watchdog("mtr_services_error", $e);
  }

  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_userconfigendpoint($user_data) {
  watchdog("mtr_services_userconfig", json_encode($user_data));

  try {

    $response = [
      "Error" => null,
      "StepName" => "UserConfig",
      "AccountName" => "4GadgetsChannel"
    ];


    /*
     * 
      $jayParsedAry = [
      "Error" => null,
      "StepName" => "AddCredentials",
      "WizardStepDescription" => "This is where you add your website credentials",
      "WizardStepTitle" => "Add Credentials",
      "ConfigItems" => [
      [
      "ConfigItemId" => "APIKey",
      "Name" => "API Key",
      "Description" => "Website API Key",
      "GroupName" => "API Credentials",
      "SortOrder" => 1,
      "SelectedValue" => "AnApiKeyGoesHere",
      "RegExValidation" => null,
      "RegExError" => null,
      "MustBeSpecified" => true,
      "ReadOnly" => false,
      "ListValues" => [
      ],
      "ValueType" => "PASSWORD"
      ],
      [
      "ConfigItemId" => "APISecretKey",
      "Name" => "API Secret Key",
      "Description" => "Website API Secret Key",
      "GroupName" => "API Credentials",
      "SortOrder" => 2,
      "SelectedValue" => "MYSuperSecretKey",
      "RegExValidation" => null,
      "RegExError" => null,
      "MustBeSpecified" => true,
      "ReadOnly" => false,
      "ListValues" => [
      ],
      "ValueType" => "PASSWORD"
      ],
      [
      "ConfigItemId" => "IsOauth",
      "Name" => "Is Oauth",
      "Description" => "Defines if the authentication type is Oauth",
      "GroupName" => "API Settings",
      "SortOrder" => 3,
      "SelectedValue" => "False",
      "RegExValidation" => null,
      "RegExError" => null,
      "MustBeSpecified" => true,
      "ReadOnly" => false,
      "ListValues" => [
      ],
      "ValueType" => "BOOLEAN"
      ],
      [
      "ConfigItemId" => "Version",
      "Name" => "Version",
      "Description" => "Version of the API",
      "GroupName" => "API Settings",
      "SortOrder" => 3,
      "SelectedValue" => "False",
      "RegExValidation" => null,
      "RegExError" => null,
      "MustBeSpecified" => true,
      "ReadOnly" => false,
      "ListValues" => [
      [
      "Display" => "1.6 - Stable",
      "Value" => "1.6.0"
      ],
      [
      "Display" => "1.6 - Beta",
      "Value" => "1.6.1"
      ],
      [
      "Display" => "1.5 - Stable",
      "Value" => "1.5.0"
      ]
      ],
      "ValueType" => "LIST"
      ]
      ]
      ];

     */
    /*
      $response = [
      "Error" => null,
      "StepName" => "AddCredentials",
      "WizardStepDescription" => "This is where you add your website credentials",
      "WizardStepTitle" => "Add Credentials",
      "ConfigItems" => [
      [
      "ConfigItemId" => "APIKey",
      "Name" => "API Key",
      "Description" => "Website API Key",
      "GroupName" => "API Credentials",
      "SortOrder" => 1,
      "SelectedValue" => "AnApiKeyGoesHere",
      "RegExValidation" => null,
      "RegExError" => null,
      "MustBeSpecified" => true,
      "ReadOnly" => false,
      "ListValues" => [
      ],
      "ValueType" => "PASSWORD"
      ],
      ]
      ];


      $response = [
      "Error" => null,
      "StepName" => "UserConfig"
      ];

     */

    $response = [
      "Error" => null,
      "StepName" => "UserConfig",
      "WizardStepDescription" => "This is where you add your website credentials",
      "WizardStepTitle" => "Add Credentials",
      "ConfigItems" => [
        [
          "ConfigItemId" => "APIKey",
          "Name" => "API Key",
          "Description" => "Website API Key",
          "GroupName" => "API Credentials",
          "SortOrder" => 1,
          "SelectedValue" => "AnApiKeyGoesHere",
          "RegExValidation" => null,
          "RegExError" => null,
          "MustBeSpecified" => true,
          "ReadOnly" => false,
          "ListValues" => [
          ],
          "ValueType" => "PASSWORD"
        ],
      ]
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_saveconfigendpoint($user_data) {

  /*
    $jayParsedAry = [
    "Error" => null,
    "StepName" => "AddCredentials",
    "WizardStepDescription" => "This is where you add your website credentials",
    "WizardStepTitle" => "Add Credentials",
    "ConfigItems" => [
    [
    "ConfigItemId" => "APIKey",
    "Name" => "API Key",
    "Description" => "Website API Key",
    "GroupName" => "API Credentials",
    "SortOrder" => 1,
    "SelectedValue" => "AnApiKeyGoesHere",
    "RegExValidation" => null,
    "RegExError" => null,
    "MustBeSpecified" => true,
    "ReadOnly" => false,
    "ListValues" => [
    ],
    "ValueType" => "PASSWORD"
    ],
    [
    "ConfigItemId" => "APISecretKey",
    "Name" => "API Secret Key",
    "Description" => "Website API Secret Key",
    "GroupName" => "API Credentials",
    "SortOrder" => 2,
    "SelectedValue" => "MYSuperSecretKey",
    "RegExValidation" => null,
    "RegExError" => null,
    "MustBeSpecified" => true,
    "ReadOnly" => false,
    "ListValues" => [
    ],
    "ValueType" => "PASSWORD"
    ],
    [
    "ConfigItemId" => "IsOauth",
    "Name" => "Is Oauth",
    "Description" => "Defines if the authentication type is Oauth",
    "GroupName" => "API Settings",
    "SortOrder" => 3,
    "SelectedValue" => "False",
    "RegExValidation" => null,
    "RegExError" => null,
    "MustBeSpecified" => true,
    "ReadOnly" => false,
    "ListValues" => [
    ],
    "ValueType" => "BOOLEAN"
    ],
    [
    "ConfigItemId" => "Version",
    "Name" => "Version",
    "Description" => "Version of the API",
    "GroupName" => "API Settings",
    "SortOrder" => 3,
    "SelectedValue" => "False",
    "RegExValidation" => null,
    "RegExError" => null,
    "MustBeSpecified" => true,
    "ReadOnly" => false,
    "ListValues" => [
    [
    "Display" => "1.6 - Stable",
    "Value" => "1.6.0"
    ],
    [
    "Display" => "1.6 - Beta",
    "Value" => "1.6.1"
    ],
    [
    "Display" => "1.5 - Stable",
    "Value" => "1.5.0"
    ]
    ],
    "ValueType" => "LIST"
    ]
    ]
    ];

   */

  watchdog("mtr_services_saveconfig", json_encode($user_data));


  try {

    $response = [
      "Error" => null,
      "StepName" => "UserConfig"
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_shippingtagsendpoint($user_data) {
  watchdog("mtr_services shippingtag", json_encode($user_data));

  try {

    $response = [
      "Error" => null,
      "ShippingTags" => [
        [
          "Tag" => "RM CLR01",
          "FriendlyName" => "Royal Mail First Class",
          "Site" => ""
        ],
        [
          "Tag" => "free_royal_mail_48_hour",
          "FriendlyName" => "Free Royal Mail 48",
          "Site" => ""
        ],
        [
          "Tag" => "dpd",
          "FriendlyName" => "DPD - Next Day",
          "Site" => ""
        ],
        [
          "Tag" => "collection",
          "FriendlyName" => "Collection",
          "Site" => ""
        ],
        [
          "Tag" => " free_shipping",
          "FriendlyName" => "Free shipping",
          "ListValues" => [
          ],
          "Site" => ""
        ]
      ]
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_paymenttagsendpoint($user_data) {
  watchdog("mtr_services_payment", json_encode($user_data));

  try {

    $response = [
      "Error" => null,
      "PaymentTags" => [
        [
          "Tag" => "paypal_verified",
          "FriendlyName" => "PayPal",
          "Site" => ""
        ],
        [
          "Tag" => "sagepay",
          "FriendlyName" => "Sagepay",
          "Site" => ""
        ],
        [
          "Tag" => "klarna",
          "FriendlyName" => "Klarna payment",
          "Site" => ""
        ],
        [
          "Tag" => "amazon_payment",
          "FriendlyName" => "Amazon payments",
          "Site" => ""
        ]
      ]
    ];



    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_configdeletedendpoint($user_data) {
  watchdog("mtr_services_configdelete", json_encode($user_data));
  $response = [
    "Error" => null,
  ];

  $output = json_encode($response);
  watchdog("mtr_services_good", $output);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_configtestendpoint($user_data) {
  watchdog("mtr_services_configtest", json_encode($user_data));
  $response = [
    "Error" => null,
  ];

  $output = json_encode($response);
  watchdog("mtr_services_good", $output);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * This call is made by Linnworks automation to get a list of orders since the last time it requested orders.
 * These calls are made every 10 to 15 minutes usually. 
 * The request expects a page result back,
 * if there are a lot of orders to return 
 * it is suggested to split the result into pages of 100 maximum.

 * */
function _mtr_services_linnworks_ordersendpoint($user_data) {

  $start = substr($user_data["UTCTimeFrom"], 0, 10) . " " . substr($user_data["UTCTimeFrom"], -9, -1);

  $start = '2020-06-14 00:00:00';

  global $user;
  $original_user = $user;
  $old_state = drupal_save_session();
  drupal_save_session(FALSE);
  $user = user_load(1);
// Take your action here where you pretend to be the user with UID = 1 (typically the admin user on a site) 
// If your code fails, it's not a problem because the session will not be saved 

  $my_view_name = 'linnworks_commerce_backoffice_orders';
  $my_display_name = 'admin_page';
  $my_view = views_get_view($my_view_name);
  $my_view->set_display($my_display_name);

  $filters = $my_view->display_handler->get_option('filters');

  // Filtering peding or completed status
 // $filters['status']['value'] = ["pending", "pending_credit", "processing", "refunded", "payment_not_cleared"];
  $filters['status']['value'] = ["pending"];
  $filters['changed_1']['value']['value'] = $start;

  $my_view->display_handler->override_option('filters', $filters);
  $my_view->execute();
  $objects = $my_view->result;

  $user = $original_user;
  drupal_save_session($old_state);

// From here on the $user is back to normal so it's OK for the session to be saved 

  $orders = [];
  $countries = _addressfield_country_options_list();

  $linnworks_order_status = ["pending" => 'PAID', "pending_credit" => 'UNPAID', "processing" => 'UNPAID', "refunded" => 'UNPAID', "payment_not_cleared" => 'UNPAID', "completed" => 'PAID'];

  foreach ($objects as $key => $object) {

    $order = $object->_field_data['order_id']['entity'];

    $wrapper = entity_metadata_wrapper('commerce_order', $order); // Order entity details.

    $billingInfo = $wrapper->commerce_customer_billing->value(); // Billing details.
    $billingaddress = $wrapper->commerce_customer_billing->commerce_customer_address->value(); // Customer Billing address.
    $shippingInfo = $wrapper->commerce_customer_shipping->value(); // Billing details.
    $shippingaddress = $wrapper->commerce_customer_shipping->commerce_customer_address->value();

    /*
      0 = 'UNPAID'
      1 = 'PAID'
      2 = 'RETURN'
      3 = 'PENDING'
      4 = 'RESEND'
     */
    
    //orderitems

    $orderitems = [];
    $shipping_cost = 0;
    // TimeZOne converstion to UTC
    $offset = date("Z");
    //$PaymentStatus = 'PAID';
    $PaymentStatus = isset($linnworks_order_status[$object->commerce_order_status]) ? $linnworks_order_status[$object->commerce_order_status] : 'PAID';
     //watchdog("mtr_services_PaymentStatus", json_encode($PaymentStatus));
     
    $currency_code = "";

    foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {

      $title = "";
      $discount_component_title = "";

      //$itemtitle = isset($line_item_wrapper->commerce_product->title->value()) ? $line_item_wrapper->commerce_product->title->value() : "";
      // watchdog("mtr_services_order_line_item_title", json_encode($itemtitle ));
      //$title = $line_item_wrapper->commerce_product->title->value();
      $discount_data = $line_item_wrapper->commerce_unit_price->data->value();

      foreach ($discount_data['components'] as $key => $component) {
        if (!empty($component['price']['data']['discount_component_title'])) {
          $discount_component_title = $component['price']['data']['discount_component_title'];
        }
      }

      //$discount_component_title = isset($discount_data['components'][1]['price']['data']['discount_component_title']) ? $discount_data['components']['price']['data']['discount_component_title'] : "";
      $currency_code = $line_item_wrapper->commerce_unit_price->currency_code->value();

      if (in_array($line_item_wrapper->type->value(), commerce_product_line_item_types())) {
        $title = $line_item_wrapper->commerce_product->title->value();
      }
      else {
        $title = $line_item_wrapper->line_item_label->value();
      }

      if (empty($title)) {
        if (!empty($discount_component_title)) {
          $ItemTitle = $discount_component_title;
        }
      }
      else {
        $ItemTitle = $title;
      }

      $internatial_delivery_item = strpos(strtolower($title), "international delivery") !== FALSE ? TRUE : FALSE;

      //$PaymentStatus = isset($linnworks_order_status[$object->commerce_order_status]) ? $linnworks_order_status[$object->commerce_order_status] : 'UNPAID';

      if (!$internatial_delivery_item) {
        if ($line_item_wrapper->commerce_unit_price->amount->value() > 0) {
          $orderitems[] = [
            "TaxCostInclusive" => true,
            "UseChannelTax" => false,
            "IsService" => false,
            "OrderLineNumber" => $delta,
            "SKU" => convert_to_alpha_numeric_hyphens($line_item_wrapper->line_item_label->value()),
            "PricePerUnit" => number_format($line_item_wrapper->commerce_unit_price->amount->value() / 100, 2),
            "Qty" => number_format($line_item_wrapper->quantity->value()),
            "TaxRate" => number_format(0),
            "LinePercentDiscount" => number_format(0),
            "ItemTitle" => $title,
            "Options" => []
          ];
        }
        else {
          $orderitems[] = [
            "TaxCostInclusive" => true,
            "UseChannelTax" => false,
            "IsService" => true,
            "OrderLineNumber" => $delta,
            "SKU" => convert_to_alpha_numeric_hyphens($ItemTitle),
            "PricePerUnit" => number_format($line_item_wrapper->commerce_unit_price->amount->value() / 100, 2),
            "Qty" => number_format(1),
            "TaxRate" => number_format(0),
            "LinePercentDiscount" => number_format(0),
            "ItemTitle" => $ItemTitle,
            "Options" => []
          ];
        }
      }
      else {
        $shipping_cost = number_format(14);
      }
    }

    $orders[] = [
      "BillingAddress" => [
        "FullName" => $billingaddress['name_line'],
        "Company" => $billingaddress['organisation_name'],
        "Address1" => $billingaddress['thoroughfare'],
        "Address2" => $billingaddress['premise'],
        "Address3" => "",
        "Town" => $billingaddress['locality'],
        "Region" => $billingaddress['administrative_area'],
        "PostCode" => $billingaddress['postal_code'],
        "Country" => $countries[$billingaddress['country']],
        "CountryCode" => $billingaddress['country'],
        "PhoneNumber" => "",
        "EmailAddress" => $order->mail
      ],
      "DeliveryAddress" => [
        "FullName" => $shippingaddress['name_line'],
        "Company" => $shippingaddress['organisation_name'],
        "Address1" => $shippingaddress['thoroughfare'],
        "Address2" => $shippingaddress['premise'],
        "Address3" => "",
        "Town" => $shippingaddress['locality'],
        "Region" => $shippingaddress['administrative_area'],
        "PostCode" => $shippingaddress['postal_code'],
        "Country" => $countries[$shippingaddress['country']],
        "CountryCode" => $shippingaddress['country'],
        "PhoneNumber" => "",
        "EmailAddress" => $order->mail
      ],
      "OrderItems" => $orderitems,
      "ExtendedProperties" => [
        [
          "Name" => "IMEI number",
          "Value" => "0",
          "Type" => "IMEI"
        ]
      ],
      "Site" => "",
      "MatchPostalServiceTag" => "Royal Mail First Class",
      "MatchPaymentMethodTag" => "Paypal",
      "PaymentStatus" => $PaymentStatus,
      "ChannelBuyerName" => "4GadgetsChannel",
      "ReferenceNumber" => $order->order_id,
      "ExternalReference" => null,
      "SecondaryReferenceNumber" => null,
      "Currency" => empty($currency_code) ? "GBP" : $currency_code,
      "ReceivedDate" => empty($order->placed) ? substr(date("c",time() - $offset), 0, -6) . ".1000000Z" : substr(date("c", $order->placed - $offset), 0, -6) . ".1000000Z",
      "DispatchBy" => empty($order->placed) ? substr(date("c",time() - $offset), 0, -6) . ".1000000Z" : substr(date("c", $order->placed - $offset), 0, -6) . ".1000000Z",
      "PostalServiceCost" => $shipping_cost,
      "PostalServiceTaxRate" => 0,
      "UseChannelTax" => false
    ];
  }
  //watchdog("mtr_services_orders_date", json_encode($user_data));

  /*

    ReceivedDate" => date('c', $order->placed),
    "DispatchBy" => date('c', $order->placed),
    "PaidOn" => date('c', $order->placed),
   * 
   */
  watchdog("mtr_services_orders", json_encode($user_data));

  try {

    $response = [
      "Error" => null,
      "HasMorePages" => false,
      "Orders" => $orders
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  module_load_include('inc', 'mtr_commerce_linnworks_stock_management');
  $settings = array();
  $authorizeByApplication = mtr_commerce_linnworks_stock_management_init($settings);

  $archived = mtr_linnworks_ExecuteCustomPagedScript($authorizeByApplication);
  $archived_items = [];
  foreach ($archived->Results as $key => $row) {

    if ($row->IsArchived) {
      $archived_items[] = $row->SKU;
    }
  }
  
   $error = "null";
  
   $entity_types = ['accessory', 'mobile_device', 'other_tech', 'smart_watch'];
  
   
    $archived_pids = [];
    $product_ids = [];
   $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'commerce_product', '=')
    ->entityCondition('bundle', $entity_types, 'IN')
    ->fieldCondition('field_linnworks_status_archived', 'value', "1", '=');


  if ($result = $query->execute()) {
    //watchdog("mtr_services archive ids", json_encode($result));
    foreach ($result["commerce_product"] as $key => $line_item) {
      $archived_pids[] = $line_item->product_id;
    }

  }

   
  foreach ($archived_items as $key => $sku) {
    //$sku = $line_item->SKU;
    $quantity = 0;
    $product_variation = commerce_product_load_by_sku($sku);
    $product_ids[] =  $product_variation->product_id;
    
    if (!isset($product_variation->field_linnworks_status_archived['und'][0]['value']) || $product_variation->field_linnworks_status_archived['und'][0]['value'] != "1") {
    $product_variation->field_linnworks_status_archived['und'][0]['value'] = "1";
    if (isset($product_variation->commerce_stock['und'][0]['value']) && $product_variation->commerce_stock['und'][0]['value'] != 0) {
      $product_variation->commerce_stock['und'][0]['value'] = $quantity;
      //product_variation->status = "0";
    }
    commerce_product_save($product_variation);
    }
  }

  
  $archived_diff = array_diff ($archived_pids,$product_ids);
 /* 
  watchdog("mtr_services archive archived_items Linn", json_encode($archived_items));
  watchdog("mtr_services archive product_ids Linn", json_encode($product_ids));
  watchdog("mtr_services archive archived_pids 4G", json_encode($archived_pids)); 
  watchdog("mtr_services archive archived_diff", json_encode($archived_diff ));
  
  */
  foreach ($archived_diff as $key => $pid) {
    
    $product_variation = commerce_product_load($pid);
    
    if (isset($product_variation->field_linnworks_status_archived['und'][0]['value'])) {
      $product_variation->field_linnworks_status_archived['und'][0]['value'] = "0";
      $product_variation->status = "1";
      commerce_product_save($product_variation);
    }
  } 
  
  if (!empty($product_variation) && $product_variation === FALSE) {

    $response = [
      "Error" => null,
      "Products" => [
        [
          "Error" => "SKU does not exist",
          "SKU" => "MyNonExistantSKU"
        ]
      ]
    ];
  }
  else {
    $response = [
      "Error" => null,
      "Products" => [
      ]
    ];
  }
  
  die();
}

function _mtr_services_linnworks_despatchendpoint($user_data) {
  watchdog("mtr_services_despatchendpoint", json_encode($user_data));

  /*
    $jayParsedAry = [
    "Orders" => [
    [
    "ReferenceNumber" => "12345",
    "ShippingVendor" => "Royal Mail",
    "ShippingMethod" => "First Class",
    "TrackingNumber" => "TrackingNumber 1",
    "SecondaryTrackingNumbers" => null,
    "ProcessedOn" => "2016-08-29T07:49:51.5036339Z",
    "Items" => [
    [
    "SKU" => "SKU1234",
    "OrderLineNumber" => "1",
    "DespatchedQuantity" => 2
    ],
    [
    "SKU" => "SKU1235",
    "OrderLineNumber" => "2",
    "DespatchedQuantity" => 2
    ]
    ]
    ]
    ],
    "AuthorizationToken" => "b7f4ee81bc4e4363adcd00eced0ea471"
    ];

   */

  try {
    $errors = [];
    // Set 4G orders to Completed
    //   $order_id = $user_data["Orders"][0]["ReferenceNumber"];

    module_load_include('inc', 'mtr_commerce_linnworks_stock_management');
    $settings = array();
    $authorizeByApplication = mtr_commerce_linnworks_stock_management_init($settings);

    foreach ($user_data["Orders"] as $key => $linnworks_order) {

      $order_id = $linnworks_order["ReferenceNumber"];


      $order_details = mtr_linnworks_GetOrderDetailsByReferenceId($authorizeByApplication, $order_id);
      $imeis = [];
      foreach ($order_details as $key2 => $order_detail) {
        $extendedproperties = isset($order_detail->ExtendedProperties) ? $order_detail->ExtendedProperties : "";
        watchdog("mtr_services_despatchendpoint extendedproperties", json_encode($extendedproperties));
        if (!empty($extendedproperties)) {
          foreach ($extendedproperties as $key2 => $extendedproperty) {
            if ($extendedproperty->Type == "IMEI" && !empty($extendedproperty->Value)) {
              $imeis[] = $extendedproperty->Value;
            }
          }
        }
      }

      watchdog("mtr_services_despatchendpoint Q3", json_encode($imeis));

      $order = (isset($order_id)) ? commerce_order_load($order_id) : FALSE;
      if ($order !== FALSE) {

        if (isset($linnworks_order["TrackingNumber"])) {
          $order->field_tracking_no['und'][0]['value'] = $linnworks_order["TrackingNumber"];
        }

        if (isset($imeis[0])) {
          $order->field_imei_no['und'][0]['value'] = implode(",", $imeis);
        }

        $order = commerce_order_status_update($order, "completed");

        $commerce_order = commerce_order_save($order);
        if ($commerce_order != "SAVED_NEW" && $commerce_order != "SAVED_UPDATED") {
          $errors[] = $order_id;
        }
      }
      else {
        $errors[] = "There is no proper Order ID";
        watchdog("mtr_services_dispatched error", "There is no proper Order ID");
      }
    }

    $orderserrors = [];
    foreach ($errors as $key => $error) {
      $orderserrors[] = [
        "Error" => "Refund failed for some reason",
        "ReferenceNumber" => $error
      ];
    }

    $response = [
      "Error" => null,
      "Orders" => $orderserrors
    ];
    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_cancelendpoint($user_data) {


  watchdog("mtr_services_linnworks_cancelendpoint", json_encode($user_data));

  /*
    $jayParsedAry = [
    "Cancellation" => [
    "ReferenceNumber" => "91489",
    "ExternalReference" => "",
    "Items" => [
    [
    "SKU" => "Apple-iPhone-XS-Max-Space-Grey-Unlocked-64GB-Pristine-MAR",
    "OrderLineNumber" => "0",
    "CancellationQuantity" => 1,
    "Reason" => "Other",
    "SecondaryReason" => ""
    ]
    ]
    ],
    "AuthorizationToken" => "zWQsST6dklLqY0dNqlDRxCcNapv5T2pOpPma_8D_0Xw"
    ];
   */
  try {
    $errors = [];
    $order_id = $user_data["Cancellation"]["ReferenceNumber"];

    foreach ($user_data["Cancellation"]["Items"] as $key => $cancelled_item) {

      // Set 4G orders to Completed

      $order = commerce_order_load($order_id);
      if ($order !== FALSE) {
        $order = commerce_order_status_update($order, "refunded");
        watchdog("mtr_services_cancellation", json_encode($order));
        //$order->field_tracking_no[0]['rendered'] = $linnworks_order["TrackingNumber"];
        $commerce_order = commerce_order_save($order);
        //watchdog("mtr_services_despatchendpoint order", json_encode($order));
        if ($commerce_order != "SAVED_NEW" && $commerce_order != "SAVED_UPDATED") {
          $errors[] = $order_id;
        }
      }
      else {
        $errors[] = "There is no proper Order ID";
        watchdog("mtr_services_cancellation error", "There is no proper Order ID");
      }
    }

    $orderserrors = [];
    foreach ($errors as $key => $error) {
      $orderserrors[] = [
        "Error" => "Cancellation failed for some reason",
        "ReferenceNumber" => $error
      ];
    }

    $response = [
      "Error" => null,
      "Orders" => $orderserrors
    ];
    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_refundendpoint($user_data) {
  watchdog("mtr_services_linnworks_refundendpoint", json_encode($user_data));

  /*
    $jayParsedAry = [
    "Refund" => [
    "ReferenceNumber" => "91291",
    "ExternalReference" => "",
    "RefundShippingAmount" => 0,
    "Items" => [
    [
    "SKU" => "Samsung-Galaxy-S10-Plus-Blue-Unlocked-128GB-Excellent-MAR",
    "OrderLineNumber" => "0",
    "RefundAmount" => 434.99,
    "Reason" => "Other",
    "SecondaryReason" => ""
    ]
    ]
    ],
    "AuthorizationToken" => "zWQsST6dklLqY0dNqlDRxCcNapv5T2pOpPma_8D_0Xw"
    ];

   */
  try {
    $errors = [];
    // Set 4G orders to Completed
    $order_id = $user_data["Refund"]["ReferenceNumber"];

    foreach ($user_data["Refund"]["Items"] as $key => $linnworks_order) {

      $order = (isset($order_id)) ? commerce_order_load($order_id) : FALSE;
      if ($order !== FALSE) {
        $order = commerce_order_status_update($order, "refunded");
        //$order = commerce_order_status_update($order, "refunded");
        watchdog("mtr_services_refundendpoint", json_encode($order));
        //   $order->field_tracking_no[0]['rendered'] = $linnworks_order["TrackingNumber"];
        $commerce_order = commerce_order_save($order);
        if ($commerce_order != "SAVED_NEW" && $commerce_order != "SAVED_UPDATED") {
          $errors[] = $order_id;
        }
      }
      else {
        $errors[] = "There is no proper Order ID";
        watchdog("mtr_services_refundendpoint error", "There is no proper Order ID");
      }
    }

    $orderserrors = [];
    foreach ($errors as $key => $error) {
      $orderserrors[] = [
        "Error" => "Refund failed for some reason",
        "ReferenceNumber" => $error
      ];
    }

    $response = [
      "Error" => null,
      "Orders" => $orderserrors
    ];
    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_archived($user_data) {
  watchdog("mtr_services_linnworks_archived", json_encode($user_data));

  /*
    $jayParsedAry = [
    "Refund" => [
    "ReferenceNumber" => "91291",
    "ExternalReference" => "",
    "RefundShippingAmount" => 0,
    "Items" => [
    [
    "SKU" => "Samsung-Galaxy-S10-Plus-Blue-Unlocked-128GB-Excellent-MAR",
    "OrderLineNumber" => "0",
    "RefundAmount" => 434.99,
    "Reason" => "Other",
    "SecondaryReason" => ""
    ]
    ]
    ],
    "AuthorizationToken" => "zWQsST6dklLqY0dNqlDRxCcNapv5T2pOpPma_8D_0Xw"
    ];

   */
  try {
    /*
      $errors = [];
      // Set 4G orders to Completed
      $order_id = $user_data["Refund"]["ReferenceNumber"];

      foreach ($user_data["Refund"]["Items"] as $key => $linnworks_order) {

      $order = (isset($order_id)) ? commerce_order_load($order_id) : FALSE;
      if ($order !== FALSE) {
      //$order = commerce_order_status_update($order, "refunded");
      $order = commerce_order_status_update($order, "completed");
      watchdog("mtr_services_refundendpoint", json_encode($order));
      //   $order->field_tracking_no[0]['rendered'] = $linnworks_order["TrackingNumber"];
      $commerce_order = commerce_order_save($order);
      if ($commerce_order != "SAVED_NEW" && $commerce_order != "SAVED_UPDATED") {
      $errors[] = $order_id;
      }
      }
      else {
      $errors[] = "There is no proper Order ID";
      watchdog("mtr_services_refundendpoint error", "There is no proper Order ID");
      }
      }

      $orderserrors = [];
      foreach ($errors as $key => $error) {
      $orderserrors[] = [
      "Error" => "Refund failed for some reason",
      "ReferenceNumber" => $error
      ];
      }
     */
    $response = [
      "Error" => null,
    ];
    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_postsaleoptionsendpoint($user_data) {
  watchdog("mtr_services_linnworks_postsaleoptionsendpoint", json_encode($user_data));
  try {

    $response = [
      "Error" => null
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_productsendpoint($user_data) {
  watchdog("mtr_services productsendpoint", json_encode($user_data));
  //watchdog("mtr_services productsendpoint C2 ", $user_data["PageNumber"]);
  // user data checking..
  // email checking..

  try {

    //get all items
    $pn = $user_data["PageNumber"];
    $products = [];
    //$order_line_items = views_get_view_result('commerce_backoffice_all_product_variations', 'page');

    $view = views_get_view('commerce_backoffice_all_product_variations');
    $view->set_display('page');
    $view->set_current_page($pn);
    $view->set_items_per_page(100);
//$view->pre_execute();
    $view->execute();
    $total = $view->total_rows;

    $results = $view->result;

    foreach ($results as $key => $line_item) {
      $products[] = [
        "SKU" => $line_item->_field_data['product_id']['entity']->sku,
        "Title" => $line_item->_field_data['product_id']['entity']->title,
        "Quantity" => $line_item->_field_data['product_id']['entity']->commerce_stock['und'][0]['value'],
        "Price" => $line_item->_field_data['product_id']['entity']->commerce_price['und'][0]['amount'] / 100,
        "Reference" => $line_item->field_product_commerce_product_nid . "-" . $line_item->product_id,
      ];
    }

    //  dpm ($order_line_items,'order_line_items');
    // get
    $response = [
      "Error" => null,
      "HasMorePages" => 100 * $pn < $total,
      "Products" => $products
    ];
    $output = json_encoded_response($response);
  }
  catch (Exception $e) {
    $output = _mtr_services_linnworks_error();
    watchdog("mtr_services_error", $e);
  }

  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_inventoryupdateendpoint($user_data) {

  watchdog("mtr_services inventoryupdate", json_encode($user_data));

  $error = "null";

  foreach ($user_data["Products"] as $key => $line_item) {
    $sku = $line_item["SKU"];
    $quantity = $line_item["Quantity"];
    $product_variation = commerce_product_load_by_sku($sku);
    // set new quantity
    watchdog("mtr_services inventoryupdate sku - quantity", json_encode($sku . " - ". $quantity));
    watchdog("mtr_services inventoryupdate pv", json_encode($product_variation));
    if (isset($product_variation->commerce_stock['und'][0]['value']) && $product_variation->commerce_stock['und'][0]['value'] != $quantity) {
      $product_variation->commerce_stock['und'][0]['value'] = $quantity;
      if ($quantity > 0 && $product_variation->status == "0") {
        $product_variation->status = "1";
      }
      commerce_product_save($product_variation);
    }
  }

  if ($product_variation === FALSE) {

    $response = [
      "Error" => null,
      "Products" => [
        [
          "Error" => "SKU does not exist",
          "SKU" => "MyNonExistantSKU"
        ]
      ]
    ];
  }
  else {
    $response = [
      "Error" => null,
      "Products" => [
      ]
    ];
  }

  $output = json_encoded_response($response);

  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_priceupdateendpoint($user_data) {
  watchdog("mtr_services priceupdate", json_encode($user_data));
  /*
    $jayParsedAry = [
    "Products" => [
    [
    "SKU" => "ABC1234",
    "Reference" => "122440",
    "Price" => 10.99,
    "Tag" => ""
    ]
    ],
    "AuthorizationToken" => "4d1aa44d211641a48da9ae269ff68975"
    ];
   */
  $error = "null";

  foreach ($user_data["Products"] as $key => $line_item) {
    $sku = $line_item["SKU"];
    $price = $line_item["Price"] * 100;
    $product_variation = commerce_product_load_by_sku($sku);
    // set new quantity
    watchdog("mtr_services priceupdate sku - price", json_encode($sku . " - " . $price));

    if (isset($product_variation->commerce_price['und'][0]['amount']) && $product_variation->commerce_price['und'][0]['amount'] != $price) {
      $product_variation->commerce_price['und'][0]['amount'] = $price;
      commerce_product_save($product_variation);
    }
  }

  if ($product_variation === FALSE) {

    $response = [
      "Error" => null,
      "Products" => [
        [
          "Error" => "SKU does not exist",
          "SKU" => "MyNonExistantSKU"
        ]
      ]
    ];
  }
  else {
    $response = [
      "Error" => null,
      "Products" => [
      ]
    ];
  }

  $output = json_encoded_response($response);

  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_inventoryupdatebatchsize($user_data) {
  try {

    $response = [
      "Error" => null
    ];

    $output = json_encoded_response($response);

    print $output;
  }
  catch (Exception $e) {
    watchdog("mtr_services_error", $e);
  }

  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_priceupdatebatchsize($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_despatchupdatebatchsize($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_getconfiguratorsettings($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_getcategories($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_getattributesbycategory($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_getvariationsbycategory($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_listingupdate($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_listingdelete($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 *
 * GET Individual Order data
 * Dependency: mtr_voucher
 * */
function _mtr_services_linnworks_checkfeed($user_data) {
  $response = [];
  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  print $output;
  die();
}

/**
 * Linworks Channel Integration - not requried fields.
 */
function _mtr_services_linnworks_notrequired() {
  $response = [
    "Error" => null,
  ];

  return json_encoded_response($response);
}

/**
 * Linworks Channel Integration - fields with errors.
 */
function _mtr_services_linnworks_error() {
  $response = [
    "Error" => "error",
  ];

  return json_encoded_response($response);
}

/*
 * Creat GUID
 */

function getGUID($type) {
  $uuid = "";
  if (function_exists('com_create_guid')) {
    $uuid = com_create_guid();
    if ($type == "short") {
      $uuid = trim(str_replace(chr(45), "", $uuid), "{}");
    }
  }
  else {
    mt_srand((double) microtime() * 10000); //optional for php 4.2.0 and up.
    $charid = md5(uniqid(rand(), true));
    if ($type == "short") {
      $uuid = substr($charid, 0, 32);
    }
    else {
      $charid = strtoupper($charid);
      $hyphen = chr(45); // "-"
      $uuid = substr($charid, 0, 8) . $hyphen
        . substr($charid, 8, 4) . $hyphen
        . substr($charid, 12, 4) . $hyphen
        . substr($charid, 16, 4) . $hyphen
        . substr($charid, 20, 12);
      // chr(123)// "{" chr(125); // "}"
    }
  }
  return ($uuid);
}

/*
 * Create json encoded response
 */

function json_encoded_response($response) {

  $output = json_encode($response);
  drupal_add_http_header('Content-Length', strlen($output));
  watchdog("mtr_services_response", $output);
  return $output;
}

/*
 * Create json encoded respons
 */

function valid_authorizationtoken($AuthorizationToken) {

  $output = TRUE;
  return $output;
}

/*
  function getGUIDshort() {
  if (function_exists('com_create_guid')) {
  return com_create_guid();
  }
  else {
  mt_srand((double) microtime() * 10000); //optional for php 4.2.0 and up.
  $charid = md5(uniqid(rand(), true));
  $uuid = substr($charid, 0, 32);
  return $uuid;
  }
  }
 */


