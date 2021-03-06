<?php
/**
 * @class
 * Purpose:
 *
 * Display:
 * Configuration:
 */
class local__project_germcollection_formatter extends ChadoFieldFormatter {

  // The default label for this field.
  public static $default_label = 'Project-Related Germplasm Collection';

  // The list of field types for which this formatter is appropriate.
  public static $field_types = array('local__project_germcollection');

  // The list of default settings for this formatter.
  public static $default_settings = array(
    'setting1' => 'default_value',
  );

   /**
    * @see ChadoFieldFormatter::settingsForm()
    *
    **/

  public function settingsForm($view_mode, $form, &$form_state) {

  }

    /**
    * @see ChadoFieldFormatter::View()
    *
    **/

  public function view(&$element, $entity_type, $entity, $langcode, $items, $display) {

    // Get the settings
    $settings = $display['settings'];

    foreach ($items as $delta => $item) {

      $link = $item['value']['schema:name'];
      if (isset($item['value']['schema:url'])) {
        $link = l($item['value']['schema:name'], $item['value']['schema:url']);
      }

      $element[$delta] = array(
        '#type' => 'markup',
        '#markup' => $link,
      );
    }
  }

    /**
    * @see ChadoFieldFormatter::settingsSummary()
    *
    **/

  public function settingsSummary($view_mode) {
    return '';
  }

}
