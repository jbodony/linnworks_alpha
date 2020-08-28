<?php

/**
 * @file
 * Includes functions related to the communication with Klarna Checkout.
 */
require_once DRUPAL_ROOT . '/../site_linnworks_config.php';

/**
 * Helper function that initiates the Klarna Checkout object.
 *
 * @param mixed $settings
 *   An array of settings.
 * @param mixed $order
 *   The Drupal Commerce order object
 *
 * @return mixed
 *   A Klarna Order object.
 */

/**
 * Page callbackLinnworks settings
 *
 * @see current_posts_menu()
 */
function mtr_commerce_linnworks_stock_management_form($form, &$form_state) {
  $form['linnworks_merchantid'] = array(
    '#type' => 'textfield',
    '#title' => t('MERCHANTID'),
    '#default_value' => variable_get('current_posts_max', 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The MERCHANTID.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function mtr_commerce_linnworks_stock_management_init($settings) {

  // Normalize settings.
  $settings['estore_id'] = isset($settings['estore_id']) ? $settings['estore_id'] : '';
  $settings['secret'] = isset($settings['secret']) ? $settings['secret'] : '';
  $settings['stored_api_key_mode'] = isset($settings['stored_api_key_mode']) ? $settings['stored_api_key_mode'] : '';
  $settings['live_mode'] = isset($settings['live_mode']) ? $settings['live_mode'] : 0;
  $settings['layout'] = isset($settings['layout']) ? $settings['layout'] : 'desktop';
// Get token
  // Server URI.
  $uri = mtr_commerce_linnworks_stock_management_get_endpoint($settings);
  // Get credentials
  list ($applicationId, $applicationSecret, $token) = mtr_commerce_linnworks_stock_management_get_credentials($settings);
  $output = mtr_linnworks_AuthorizeByApplication($uri, $applicationId, $applicationSecret, $token);
  return $output;
}

/**
 * Helper function that returns the Klarna Checkout endpoint.
 *
 * @param mixed $settings
 *   An array of settings.
 *
 * @return strings
 *   The Klarna Checkout endpoint URI
 */
function mtr_commerce_linnworks_stock_management_get_endpoint($settings) {
  // Server URI.
  if ($settings['live_mode']) {
    $uri = 'https://api.linnworks.net';
  }
  else {
    $uri = 'https://api.linnworks.net';
  }
  return $uri;
}

/**
 * Helper function that returns the Klarna Credentials .
 *
 * @param mixed $settings
 *   An array of settings.
 *
 * @return array
 *   merchantId & sharedSecret
 */
function mtr_commerce_linnworks_stock_management_get_credentials($settings) {

  // Server credentials.
  if ($settings['live_mode']) {
    $applicationId = MTR_4GADGETS_LINNWORKS_DEVELOPER_APPLICATIONID;
    $sharedSecret = MTR_4GADGETS_LINNWORKS_DEVELOPER_SECRETID;
    $token = MTR_4GADGETS_LINNWORKS_DEVELOPER_TOKEN;
  }
  else {
    $applicationId = MTR_4GADGETS_LINNWORKS_DEVELOPER_APPLICATIONID;
    $sharedSecret = MTR_4GADGETS_LINNWORKS_DEVELOPER_SECRETID;
    $token = MTR_4GADGETS_LINNWORKS_DEVELOPER_TOKEN;
  }

  return [$applicationId, $sharedSecret, $token];
}

/**
 * Helper function that returns the Klarna Checkout object.
 *
 * @param mixed $order
 *   The Drupal Commerce order object.
 * @param int $checkout_id
 *   The checkout ID returned by Klarna.
 *
 * @return mixed
 *   A Klarna Order object.
 */
function mtr_commerce_linnworks_stock_management_get_products($order, $checkout_id) {

  try {
    
  }
  catch (Exception $e) {
    drupal_set_message(t('Klarna experienced a problem creating the payment.' .
        'Please contact the website administrator. Caught exception: ' . $e->getMessage()));
  }

  return $checkout;
}

function mtr_linnworks_AuthorizeByApplication($uri, $applicationId, $applicationSecret, $token) {
  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => "$uri//api/Auth/AuthorizeByApplication",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "applicationId=$applicationId&applicationSecret=$applicationSecret&token%20=$token",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded"
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

function mtr_linnworks_GetStockItemsFull($authorizeByApplication) {
  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/GetStockItemsFull",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "keyword=&loadCompositeParents=True&loadVariationParents=False&entriesPerPage=10&pageNumber=1&dataRequirements=%5B0%2C1%2C2%2C3%2C4%2C5%2C6%2C7%2C8%5D&searchTypes=%5B0%2C1%2C2%5D",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_GetInventoryItemLocations($authorizeByApplication,$inventoryItemId) {
  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/GetInventoryItemLocations",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemId=".$inventoryItemId,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

function mtr_linnworks_UpdateStockLevelsBySKU($authorizeByApplication, $post) {

  $curl = curl_init();
/*
  $post = [
    "SKU" => $sku,
    "LocationId" => "00000000-0000-0000-0000-000000000000",
    "Level" => $diff
  ];
*/
  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/UpdateStockLevelsBySKU",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "stockLevels=" . urlencode("[" . $post_json . "]") . "&changeSource=4Gadgets",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_SetStockLevel($authorizeByApplication, $sku, $level) {

  $curl = curl_init();

  $post = [
    "SKU" => $sku,
    "LocationId" => "00000000-0000-0000-0000-000000000000",
    "Level" => $level
  ];

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/UpdateStockLevelsBySKU",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "stockLevels=" . urlencode("[" . $post_json . "]") . "&changeSource=4Gadgets",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_GetStockLevel($authorizeByApplication, $StockItemId) {

  $curl = curl_init();

 // $post_json = json_encode($post, JSON_FORCE_OBJECT);
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/GetStockLevel",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "stockItemId=" . $StockItemId,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


// Get GetStockItemIdsBySKU

function mtr_linnworks_GetStockItemIdsBySKU($authorizeByApplication, $sku) {

  $curl = curl_init();

  $post = [
    "SKUS" => [$sku]
  ];

  $post_json = json_encode($post);
  //dpm("request=" . urlencode($post_json), '$post_json');
  //dpm ($post_json ,'$post_json' );
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/GetStockItemIdsBySKU",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "request=" . urlencode($post_json),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

// GetInventoryItemExtendedProperties

function mtr_linnworks_GetInventoryItemExtendedProperties($authorizeByApplication, $StockItemIntId) {

  $curl = curl_init();

  $post = [
    "PropertyName" => $sku,
    "propertyParams" => "00000000-0000-0000-0000-000000000000",
  ];

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api Inventory/GetInventoryItemExtendedProperties",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemId=7a0f29bf-329d-412b-851c-8b57778282&propertyParams=" . urlencode("[" . $post_json . "]") . "&changeSource=4Gadgets",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}




// CreateInventoryItemChannelSKUs

function mtr_linnworks_CreateInventoryItemChannelSKUs($authorizeByApplication, $post) {

  $curl = curl_init();

  $post_json = json_encode($post);
  //dpm ($post_json, "CreateInventoryItemChannelSKUs");
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/CreateInventoryItemChannelSKUs",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemChannelSKUs=" . urlencode("[" . $post_json . "]"),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

// CreateInventoryItemChannelSKUs

function mtr_linnworks_CreateInventoryItemPrices($authorizeByApplication, $post) {

  $curl = curl_init();

  $post_json = json_encode($post);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/CreateInventoryItemPrices",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemPrices=" . urlencode("[" . $post_json . "]"),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


// CheckVariationParentSKUExists

function mtr_linnworks_CheckVariationParentSKUExists($authorizeByApplication, $post) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/CheckVariationParentSKUExists",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "parentSKU=" . urlencode($post),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


// CreateVariationGroup

function mtr_linnworks_CreateVariationGroup($authorizeByApplication, $post) {

  $curl = curl_init();

  $post_json = json_encode($post);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/CreateVariationGroup",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "template=" . urlencode($post_json),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

// GetVariationGroupByName

function mtr_linnworks_GetVariationGroupByName($authorizeByApplication, $post) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/GetVariationGroupByName",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "variationName=" . urlencode($post),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

// AddVariationItems

function mtr_linnworks_AddVariationItems($authorizeByApplication, $post) {

  $curl = curl_init();

  //$post_json = json_encode($post['pkStockItemIds']);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/AddVariationItems",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "pkVariationItemId=" . $post['pkVariationItemId'] . '&pkStockItemIds=["'.$post['pkStockItemIds'].'"]',
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


// UpdateInventoryItemExtendedProperties

function mtr_linnworks_CreateInventoryItemExtendedProperties($authorizeByApplication, $post) {

  $curl = curl_init();

  /*
   * 
   *   {
    "pkRowId": "4a58f56b-f5e7-4525-b143-eeb871da8bff",
    "fkStockItemId": "804f4f5e-c75b-45b5-8527-5b682884ad62",
    "ProperyName": "sample string 3",
    "PropertyValue": "sample string 4",
    "PropertyType": "sample string 5"
    }
   * 
   */

  $post_json = json_encode($post);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/CreateInventoryItemExtendedProperties",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemExtendedProperties=" . urlencode($post_json),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

// UpdateInventoryItemExtendedProperties

function mtr_linnworks_UpdateInventoryItemExtendedProperties($authorizeByApplication, $sku, $diff) {

  $curl = curl_init();


  /*
   * 
   *   {
    "pkRowId": "4a58f56b-f5e7-4525-b143-eeb871da8bff",
    "fkStockItemId": "804f4f5e-c75b-45b5-8527-5b682884ad62",
    "ProperyName": "sample string 3",
    "PropertyValue": "sample string 4",
    "PropertyType": "sample string 5"
    }
   * 
   */
  $post = [
    "SKU" => $sku,
    "LocationId" => "00000000-0000-0000-0000-000000000000",
    "Level" => $diff
  ];

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Stock/UpdateInventoryItemExtendedProperties",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItemExtendedProperties=" . urlencode("[" . $post_json . "]"),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

function mtr_linnworks_UpdateInventoryItem($authorizeByApplication, $StockItemId, $post) {

  $curl = curl_init();

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/UpdateInventoryItem",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItem=" . urlencode("[" . $post_json . "]"),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

function mtr_linnworks_AddInventoryItem($authorizeByApplication, $post) {

  $curl = curl_init();

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/AddInventoryItem",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "inventoryItem=" . urlencode($post_json),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_AddImageToInventoryItem($authorizeByApplication, $post) {

  $curl = curl_init();

  $post_json = json_encode($post, JSON_FORCE_OBJECT);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/AddImageToInventoryItem",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "request=" . urlencode($post_json),
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_getCategories($authorizeByApplication) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/getCategories",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


// Ordering


function mtr_linnworks_GetOpenOrderIdByOrderOrReferenceId($authorizeByApplication, $post) {

  $curl = curl_init();
   // dpm ($post,"post");
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/GetOpenOrderIdByOrderOrReferenceId",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "orderOrReferenceId=" . $post,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);
  // dpm ($response,"post response");
  curl_close($curl);

  return (json_decode($response));
}





function mtr_linnworks_ChangeStatus($authorizeByApplication, $linnworksOrderId,$status) {

  $curl = curl_init();

  
  /*
   0 = 'UNPAID'
1 = 'PAID'
2 = 'RETURN'
3 = 'PENDING'
4 = 'RESEND' 
   */
  
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/ChangeStatus",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => 'orderIds=["' . $linnworksOrderId . '"]' . '&status=' . $status,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}





function mtr_linnworks_CompleteOrder($authorizeByApplication, $post) {

  $curl = curl_init();
 dpm ($post, "complete Orderx");
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/CompleteOrder",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "orderId=" . $post,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}



function mtr_linnworks_DeleteOrder($authorizeByApplication, $post) {

  watchdog("mtr_services DeleteOrder", json_encode($post)); 
  $curl = curl_init();
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/DeleteOrder",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "orderId=" . $post,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_CancelOrder($authorizeByApplication, $post) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/CancelOrder",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => "orderId=" . $post ."&e=cancellationerror",
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}



function mtr_linnworks_LockOrder($authorizeByApplication, $linnworksOrderId,$post) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/LockOrder",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => 'orderIds=["' .  $linnworksOrderId .'"]&lockOrder='.$post,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_ArchiveInventoryItems($authorizeByApplication, $post) {

  $curl = curl_init();
  $post_json = json_encode($post);

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Inventory/ArchiveInventoryItems",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => 'parameters=' . $post_json,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}


function mtr_linnworks_GetOrderDetailsByReferenceId($authorizeByApplication, $post) {

  $curl = curl_init();

  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Orders/GetOrderDetailsByReferenceId",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => 'ReferenceId=' . $post,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}

function mtr_linnworks_ExecuteCustomPagedScript($authorizeByApplication) {

  $curl = curl_init();
  $postfields = "scriptId=6&parameters=[]&entriesPerPage=10000&pageNumber=1&cancellationToken={}";
  curl_setopt_array($curl, array(
    CURLOPT_URL => $authorizeByApplication->Server . "/api/Dashboards/ExecuteCustomPagedScript",
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_ENCODING => "",
    CURLOPT_MAXREDIRS => 10,
    CURLOPT_TIMEOUT => 0,
    CURLOPT_FOLLOWLOCATION => true,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "POST",
    CURLOPT_POSTFIELDS => $postfields,
    CURLOPT_HTTPHEADER => array(
      "Content-Type: application/x-www-form-urlencoded",
      "Authorization: " . $authorizeByApplication->Token
    ),
  ));

  $response = curl_exec($curl);

  curl_close($curl);

  return (json_decode($response));
}