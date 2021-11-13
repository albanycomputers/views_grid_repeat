<?php

/**
 * @file
 * Contains the views_grid_repeat style plugin.
 */

class views_plugin_style_views_grid_repeat extends views_plugin_style {

  /**
   * Set default options
   */
  // function options(&$options) {
    // parent::options($options);


function option_definition() {
    $options = parent::option_definition();
    $options['layout_type'] = array('default' => 'fit_grid');
    $options['layout_width_value'] = array('default' => 300);
    $options['layout_width_height'] = array('default' => 300);
    $options['layout_width_unit'] = array('default' => 'px');
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['layout_info'] = array(
      '#markup' => '<h4>' . t('Layout tips') . '</h4><p>' . t('To use the settings in the View enter values in the fields below.  To use your own CSS then make sure the fields below are empty.') . '</p>',
    );
    $form['layout_type'] = array(
      '#type' => 'radios',
      '#title' => t('Layout Type'),
      '#options' => array('fit_grid' => t('CSS3 Fit Grid'), 'fill_grid' => t('CSS3 Fill Grid')),
      '#default_value' => $this->options['layout_type'],
      '#description' => t('Choose either Fit or Fill.  Fit will expand the column to fit the content to the available space.  Fill will have as many columns as needed but will keep the minimum and maximum size, If there is not enough columns to fit the width, you will have a visible space on the left.'),
    );
    $form['layout_width_value'] = array(
      '#type' => 'number',
      '#title' => t('Content width'),
      '#size' => 20,
      '#maxlength' => 4,
      '#min' => 0,
      '#max' => 9999,
      '#default_value' => $this->options['layout_width_value'],
      '#description' => t('Enter the desired width of the content or column. Use 0 to disable the CSS when using your own CSS. Default is 300px using the Unit Type of px (pixels) below.'),
    );
    $form['layout_width_height'] = array(
      '#type' => 'number',
      '#title' => t('Minimum row height'),
      '#size' => 20,
      '#maxlength' => 4,
      '#min' => 0,
      '#max' => 9999,
      '#default_value' => $this->options['layout_width_height'],
      '#description' => t('Enter the minimum height of the content type. Use 0 to disable the CSS when using your own CSS. Default is 300px using the Unit Type of px (pixels) below.'),
    );
    $form['layout_width_unit'] = array(
      '#type' => 'textfield',
      '#title' => t('Unit type for width and height.'),
      '#size' => 20,
      '#maxlength' => 3,
      '#default_value' => $this->options['layout_width_unit'],
      '#description' => t('Enter the desired width and heigh unite of measure. Example CSS units are px % cm ren em etc...'),
    );
  }
}